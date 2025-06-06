# UTF-8 Validation

## Description

This project contains a solution for validating UTF-8 encoding in a given dataset. The function determines whether a list of integers represents valid UTF-8 encoded data.

## Problem Statement

Write a method that determines if a given data set represents a valid UTF-8 encoding.

## Requirements

- Prototype: `def validUTF8(data)`
- Return: `True` if data is a valid UTF-8 encoding, else return `False`
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer

## Files

- `0-validate_utf8.py`: Contains the `validUTF8` function implementation

## UTF-8 Encoding Rules

UTF-8 uses the following byte patterns:

1. **1-byte characters (ASCII)**: `0xxxxxxx`
2. **2-byte characters**: `110xxxxx 10xxxxxx`
3. **3-byte characters**: `1110xxxx 10xxxxxx 10xxxxxx`
4. **4-byte characters**: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`

Where `x` represents variable bits and continuation bytes always start with `10`.

## Algorithm

The solution works by:

1. **Iterating** through each byte in the data
2. **Determining** the expected number of bytes for each character based on the first byte pattern
3. **Validating** that the correct number of continuation bytes follow
4. **Checking** that continuation bytes follow the `10xxxxxx` pattern
5. **Returning** `False` if any validation fails, `True` if all data is valid

## Usage

```python
#!/usr/bin/python3

validUTF8 = __import__('0-validate_utf8').validUTF8

# Valid ASCII
data = [65]  # 'A'
print(validUTF8(data))  # True

# Valid multi-byte UTF-8
data = [197, 130]  # Valid 2-byte character
print(validUTF8(data))  # True

# Invalid UTF-8
data = [229, 165]  # Incomplete 3-byte sequence
print(validUTF8(data))  # False
```

## Test Cases

The implementation handles various scenarios:
- Single ASCII characters
- Multi-byte UTF-8 characters (2, 3, and 4 bytes)
- Invalid start bytes
- Incomplete sequences
- Invalid continuation bytes

## Environment

- Ubuntu 14.04 LTS
- Python 3 (version 3.4.3)
- PEP 8 style (version 1.7.x)