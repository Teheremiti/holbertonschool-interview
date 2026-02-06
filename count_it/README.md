# Count It

A recursive function that queries the Reddit API to count keyword occurrences in hot article titles.

## Description

This module provides a function `count_words` that:
- Queries the Reddit API for hot articles in a given subreddit
- Parses the title of all hot articles
- Counts occurrences of given keywords (case-insensitive)
- Prints a sorted count of the keywords

## Usage

```python
count_words = __import__('0-count').count_words
count_words("programming", ["python", "java", "javascript"])
```

## Requirements

- Python 3.4.3+
- Requests module (`pip install requests`)

## Features

- **Recursive**: Uses recursion to handle pagination from the Reddit API
- **Case-insensitive**: Keywords are matched regardless of case
- **Duplicate handling**: If the same keyword appears multiple times in the word list, counts are summed
- **Exact matching**: Only exact word matches count (e.g., "java." or "java_" do not count as "java")
- **Sorted output**: Results are sorted by count (descending), then alphabetically (ascending)
- **Invalid subreddit handling**: Returns nothing for invalid subreddits (does not follow redirects)
