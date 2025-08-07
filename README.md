# Overview

The software is a command-line calculator written in C++ that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. It uses variables, expressions, conditionals, loops, and functions to handle user input, perform calculations, and display results. A Calculator class organizes the program’s logic, while an STL vector stores the history of calculations. The program also includes file handling to save and display past operations, demonstrating key C++ concepts in a simple and practical application.

The purpose of writing this software was to demonstrate my understanding of basic C++ programming concepts such as:

1. Variables

2. Expressions

3. Conditionals

4. Loops

5. Functions

6. Classes

7. Data structure from STL (such as a vector, list, or map)

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

Visual Studio Code, MinGW compiler, C++ IntelliSense and C/C++ Debugger

C++

# Useful Websites

- [Microsoft Learn](https://learn.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-170)
- [Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B)
- [GCC Online Documentation](https://gcc.gnu.org/onlinedocs/)

# Future Work

- Implement a formatNumber() helper function to automatically remove unnecessary decimal places when the number is whole.
- Add input validation for numbers using cin.peek() or by reading input as strings and parsing them safely
- Extend functionality to support more advanced operations

{g++ calculator.cpp -o calculator.exe}
{./calculator.exe}