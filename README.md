# Password Generator in C++

## Description
This project contains two different C++ programs that generate passwords based on a specified maximum password length and alphabet length. Both programs offer a way to generate all possible combinations of passwords using lowercase English letters (a-z), but they use different methods for password generation:

- **Recursive Password Generator:** Uses recursion to generate passwords of varying lengths.
- **Queue-based Password Generator:** Uses a queue to generate passwords in a breadth-first manner, ensuring that shorter passwords are generated first.

## Features
- Generates passwords of varying lengths, from 1 to the maximum password length.
- Customizable alphabet length, allowing you to control how many lowercase English letters are used to generate the passwords.

**Recursive Password Generator:**
- Uses recursion to generate all combinations for each password length.

**Queue-based Password Generator:**
- Uses a queue data structure to generate passwords in a breadth-first order.

## How to Run
To compile either of the programs, use the following command: 
`g++ -o password_generator password_generator.cpp`
To run the programs, use the following syntax: 
`./password_generator -max_password_length -alphabet_length`
**Example**
To generate passwords of lengths 1 to 3 using the first 5 letters of the alphabet (a, b, c, d, e):
`./password_generator 3 5`

## Example Output
```
a
b
c
d
e
aa
ab
ac
ad
ae
ba
bb
bc
bd
be
...
```

## Error Handling
If you do not provide the correct number of arguments, the program will display a usage message.
The program will also ensure that:
- Both arguments are positive integers.
- The alphabet length does not exceed 26 (since there are only 26 letters in the alphabet).
**Example Error Messages**
If the number of arguments is incorrect:
`Usage: ./password_generator.exe -max_password_length -alphabet_length`
If invalid argument values are provided:
`Error: Both values should be positive integers, and alphabet_length should not exceed 26`