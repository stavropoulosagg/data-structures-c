#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "STACK.h"
#include "Item.h"
#include "eval_infix.h"

#define MAX_OUTPUT_SIZE 1000

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int apply_operator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluate_postfix(const char* postfix) {
    Stack value_stack = STACKempty();

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isspace(postfix[i])) continue;

        if (isdigit(postfix[i])) {
            int val = 0;
            while (isdigit(postfix[i])) {
                val = val * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            STACKpush(value_stack, val);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int b = STACKpop(value_stack);
            int a = STACKpop(value_stack);
            int result = apply_operator(a, b, postfix[i]);
            STACKpush(value_stack, result);
        }
    }

    return STACKpop(value_stack);
}

void infix_to_postfix(const char* expr, char* output) {
    Stack op_stack = STACKempty();
    int out_index = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            while (isdigit(expr[i])) {
                output[out_index++] = expr[i++];
            }
            output[out_index++] = ' ';
            i--;
        } else if (expr[i] == '(') {
            STACKpush(op_stack, expr[i]);
        } else if (expr[i] == ')') {
            while (!STACKempty(op_stack) && STACKtop(op_stack) != '(') {
                output[out_index++] = STACKpop(op_stack);
                output[out_index++] = ' ';
            }
            STACKpop(op_stack); // remove '('
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!STACKempty(op_stack) && precedence(STACKtop(op_stack)) >= precedence(expr[i])) {
                output[out_index++] = STACKpop(op_stack);
                output[out_index++] = ' ';
            }
            STACKpush(op_stack, expr[i]);
        }
    }

    while (!STACKempty(op_stack)) {
        output[out_index++] = STACKpop(op_stack);
        output[out_index++] = ' ';
    }

    output[out_index] = '\0';
}

int evaluate_infix_expression(const char* expr) {
    char postfix[MAX_OUTPUT_SIZE];
    infix_to_postfix(expr, postfix);
    return evaluate_postfix(postfix);
}
