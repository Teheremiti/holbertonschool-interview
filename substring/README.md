Substring with concatenated words
=================================

This project implements a function that finds all starting indices of substrings within a string that are formed by concatenating a list of words exactly once, in any order, with no extra characters.

Prototype
---------

```c
int *find_substring(char const *s, char const **words,
		    int nb_words, int *n);
```

- **`s`**: input string to scan.
- **`words`**: array of words that must all appear, concatenated, in the substring.
- **`nb_words`**: number of words in the `words` array (all must have the same length).
- **`n`**: output parameter where the function stores the number of starting indices found.

The function returns a dynamically allocated array of `int` containing the starting indices in `s` where a valid concatenation is found, or `NULL` if no such substring exists or on error. When `NULL` is returned, `*n` is set to `0`.

Compilation
-----------

Example compilation with the provided test `main.c`:

```bash
gcc -Wall -Werror -Wextra -pedantic main.c substring.c -o substring
```

Then run:

```bash
./substring "barfoothefoobarman" "foo" "bar"
```