# Infix Expression Evaluation via Postfix Conversion (C)

This project implements a complete infix expression evaluator in C by first converting the infix expression to postfix notation and then evaluating the postfix result.

## Overview

The program accepts arithmetic expressions written in infix notation (e.g., `3 + 4 * (2 - 1)`) and evaluates them using the following two-step process:

1. **Infix to Postfix Conversion**  
   Implements a version of the *Shunting Yard algorithm* using a stack to handle operator precedence and parentheses.

2. **Postfix Evaluation**  
   Once converted, the postfix expression is evaluated using a second stack to produce the final result.

## Features

- Supports basic operators: `+`, `-`, `*`, `/`
- Handles parentheses and operator precedence
- Multi-digit integer support
- Whitespace-tolerant
- Modular C code with header files and unit tests

## File Structure

- `eval_infix.h` – Header file with function declarations
- `eval_infix.c` – Contains the core logic for conversion and evaluation
- `main.c` – Demonstrates evaluating an example expression
- `test_eval_infix.c` – Unit tests using the Acutest framework
- `acutest.h` – Lightweight unit testing framework (included locally)

## Example

Input expression:

(3 + 2) * (4 - 1)

Postfix conversion:

3 2 + 4 1 - *

Evaluation result:

15


## Compilation and Usage

To compile and run the demo:

gcc main.c eval_infix.c -o eval_infix
./eval_infix

To run unit tests:

gcc test_eval_infix.c eval_infix.c -o test_eval
./test_eval
