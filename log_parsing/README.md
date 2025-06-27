# 0x03. Log Parsing

## Description

This project contains a Python script that reads log data from stdin line by line and computes metrics.

## Requirements

* Allowed editors: vi, vim, emacs
* All files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
* All files should end with a new line
* The first line of all files should be exactly `#!/usr/bin/python3`
* A README.md file, at the root of the folder of the project, is mandatory
* Code should use the PEP 8 style (version 1.7.x)
* All files must be executable
* The length of files will be tested using wc

## Files

### 0-stats.py

A script that reads stdin line by line and computes metrics:

**Input format:** `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`

**Features:**
- Parses log lines according to the specified format
- Skips lines that don't match the format
- After every 10 lines and/or keyboard interruption (CTRL + C), prints statistics:
  - Total file size: sum of all previous file sizes
  - Number of lines by status code (200, 301, 400, 401, 403, 404, 405, 500)
  - Status codes are printed in ascending order
  - Only prints status codes that appear

**Usage:**
```bash
./0-generator.py | ./0-stats.py
```