#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """
    Determine if a given data set represents a valid UTF-8 encoding.

    Args:
    data (list): List of integers representing bytes of data

    Returns:
    bool: True if data is a valid UTF-8 encoding, else False

    UTF-8 encoding rules:
    - 1-byte: 0xxxxxxx
    - 2-byte: 110xxxxx 10xxxxxx
    - 3-byte: 1110xxxx 10xxxxxx 10xxxxxx
    - 4-byte: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    """
    def get_byte_count(byte):
        """
        Determine how many bytes a UTF-8 character should have
        based on the first byte.

        Returns:
            int: Number of bytes (1-4), or 0 if invalid
        """
        if (byte & 0b10000000) == 0:  # 0xxxxxxx
            return 1
        elif (byte & 0b11100000) == 0b11000000:  # 110xxxxx
            return 2
        elif (byte & 0b11110000) == 0b11100000:  # 1110xxxx
            return 3
        elif (byte & 0b11111000) == 0b11110000:  # 11110xxx
            return 4
        else:
            return 0  # Invalid start byte

    def is_continuation_byte(byte):
        """
        Check if a byte is a valid continuation byte (10xxxxxx).
        """
        return (byte & 0b11000000) == 0b10000000

    i = 0
    while i < len(data):
        # Get only the 8 least significant bits
        byte = data[i] & 0xFF

        # Determine how many bytes this character should have
        byte_count = get_byte_count(byte)

        if byte_count == 0:
            return False

        # Check if we have enough bytes remaining
        if i + byte_count > len(data):
            return False

        # Validate continuation bytes
        for j in range(1, byte_count):
            continuation_byte = data[i + j] & 0xFF
            if not is_continuation_byte(continuation_byte):
                return False

        i += byte_count

    return True
