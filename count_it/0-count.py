#!/usr/bin/python3
"""
Module for counting keywords in Reddit hot article titles.
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords.

    Args:
        subreddit: The subreddit to query.
        word_list: A list of keywords to count (case-insensitive).
        after: The pagination parameter for Reddit API (used in recursion).
        word_count: A dictionary to accumulate word counts (used in recursion).

    Returns:
        None. Prints the results when recursion is complete.
    """
    # Build multiplier dict for handling duplicates in word_list
    word_multiplier = {}
    for word in word_list:
        word_lower = word.lower()
        word_multiplier[word_lower] = word_multiplier.get(word_lower, 0) + 1

    if word_count is None:
        word_count = {}
        # Initialize word_count with all unique words from word_list
        for word in word_list:
            word_lower = word.lower()
            if word_lower not in word_count:
                word_count[word_lower] = 0

    # Build the URL
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:count_it:v1.0 (by /u/holberton)"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    # Make the request without following redirects
    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )
    except requests.RequestException:
        return

    # Check for valid response (not a redirect, not an error)
    if response.status_code != 200:
        return

    # Parse the JSON response
    try:
        data = response.json()
    except ValueError:
        return

    # Get the list of posts
    try:
        posts = data["data"]["children"]
        next_after = data["data"]["after"]
    except (KeyError, TypeError):
        return

    # Count words in each post title
    for post in posts:
        try:
            title = post["data"]["title"].lower()
            # Split title into words by whitespace
            title_words = title.split()
            for title_word in title_words:
                # Only count words that are purely alphanumeric
                # This ensures java. java! java_ don't count as java
                if title_word.isalnum() and title_word in word_count:
                    # Add the multiplier (handles duplicates in word_list)
                    word_count[title_word] += word_multiplier[title_word]
        except (KeyError, TypeError):
            continue

    # If there are more pages, recurse
    if next_after:
        return count_words(subreddit, word_list, next_after, word_count)

    # No more pages - print results
    # Sort by count (descending), then alphabetically (ascending)
    sorted_words = sorted(
        word_count.items(),
        key=lambda x: (-x[1], x[0])
    )

    for word, count in sorted_words:
        if count > 0:
            print("{}: {}".format(word, count))
