# Linked List Palindrome

## Description
Function that checks if a singly linked list is a palindrome.

## Prototype
```c
int is_palindrome(listint_t **head);
```

## Return
- `1` if the list is a palindrome
- `0` if it is not
- An empty list is considered a palindrome

## Files
| File | Description |
|---|---|
| `lists.h` | Header file with struct and prototypes |
| `0-is_palindrome.c` | Palindrome check implementation |
| `linked_lists.c` | Utility functions (print, add, free) |
| `0-main.c` | Example main for testing |

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```
