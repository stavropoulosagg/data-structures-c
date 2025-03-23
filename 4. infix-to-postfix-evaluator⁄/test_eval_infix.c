#include <stdio.h>
#include "acutest.h"
#include "eval_infix.h"  // your module

void test_basic_expressions() {
    TEST_CHECK(evaluate_infix_expression("3 + 4") == 7);
    TEST_CHECK(evaluate_infix_expression("3 + 4 * 2") == 11);
    TEST_CHECK(evaluate_infix_expression("(1 + 2) * (3 + 4)") == 21);
    TEST_CHECK(evaluate_infix_expression("8 / 2 + 3") == 7);
    TEST_CHECK(evaluate_infix_expression("10 - 5 * 2") == 0);
}

void test_whitespace_and_order() {
    TEST_CHECK(evaluate_infix_expression("   5 +   3 * 2 ") == 11);
    TEST_CHECK(evaluate_infix_expression("( 6 + 2 ) / 2") == 4);
}

TEST_LIST = {
    { "basic expressions", test_basic_expressions },
    { "whitespace and order", test_whitespace_and_order },
    { NULL, NULL }
};
