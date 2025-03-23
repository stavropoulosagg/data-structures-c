#include <stdio.h>
#include "eval_infix.h"

int main() {
    const char* expr1 = "3 + 4 * 2";
    const char* expr2 = "(1 + 2) * (3 + 4)";

    printf("Expression: %s\nResult: %d\n\n", expr1, evaluate_infix_expression(expr1));
    printf("Expression: %s\nResult: %d\n\n", expr2, evaluate_infix_expression(expr2));

    return 0;
}
