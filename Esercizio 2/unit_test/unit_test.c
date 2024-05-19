#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "unity_internals.h"
#include "../skiplist/skip_list.h"
#include "../misc/compar.h"
#include <string.h>

static int v1, v2, v3;
static double d1, d2, d3;
static char c1, c2, c3;

void setUp(void)
{
    v1 = 1;
    v2 = 2;
    v3 = 3;

    d1 = 1.0;
    d2 = 2.0;
    d3 = 3.0;

    c1 = 'a';
    c2 = 'b';
    c3 = 'c';
}

void tearDown(){

}

static void test_add_one_element_int(void) {
    int *input = {&v1};

    Skiplist *list = initSkiplist(list, 1, compar_int);
    addItem(list, (void *)input);
    int *expected = (int *)searchSkipList(list, (void *)input);
    TEST_ASSERT_EQUAL_INT(expected, input);
}

static void test_add_three_elements_int(void) {
    int *a = {&v1};
    int *b = {&v2};
    int *c = {&v3};

    Skiplist *list = initSkiplist(list, 1, compar_int);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    int *expected = (int *)searchSkipList(list, (void *)a);
    TEST_ASSERT_EQUAL_INT(expected, a);

    expected = (int *)searchSkipList(list, (void *)b);
    TEST_ASSERT_EQUAL_INT(expected, b);

    expected = (int *)searchSkipList(list, (void *)c);
    TEST_ASSERT_EQUAL_INT(expected, c);
}

static void test_order_three_elements_int(void) {
    int *a = {&v1};
    int *b = {&v2};
    int *c = {&v3};

    Skiplist *list = initSkiplist(list, 1, compar_int);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    Node *tmp = list->header;
    int *expA = tmp->next[0]->val;
    tmp = tmp->next[0];
    int *expB = tmp->next[0]->val;
    tmp = tmp->next[0];
    int *expC = tmp->next[0]->val;
    tmp = tmp->next[0];

    TEST_ASSERT_EQUAL_INT(expA, a);
    TEST_ASSERT_EQUAL_INT(expB, b);
    TEST_ASSERT_EQUAL_INT(expC, c);
    TEST_ASSERT_NULL(tmp->next[0]);
}

static void test_add_one_element_double(void) {
    double *input = {&d1};

    Skiplist *list = initSkiplist(list, 1, compar_double);
    addItem(list, (void *)input);
    double *expected = (double *)searchSkipList(list, (void *)input);
    TEST_ASSERT_EQUAL_PTR(expected, input);
}

static void test_add_three_elements_double(void) {
    double *a = {&d1};
    double *b = {&d2};
    double *c = {&d3};

    Skiplist *list = initSkiplist(list, 1, compar_double);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    double *expA = (double *)searchSkipList(list, (void *)a);
    double *expB = (double *)searchSkipList(list, (void *)b);
    double *expC = (double *)searchSkipList(list, (void *)c);

    TEST_ASSERT_EQUAL_DOUBLE(*expA, *a);
    TEST_ASSERT_EQUAL_DOUBLE(*expB, *b);
    TEST_ASSERT_EQUAL_DOUBLE(*expC, *c);
}

static void test_order_three_elements_double(void) {
    double *a = {&d1};
    double *b = {&d2};
    double *c = {&d3};

    Skiplist *list = initSkiplist(list, 1, compar_double);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    Node *tmp = list->header;
    double *expA = tmp->next[0]->val;
    tmp = tmp->next[0];
    double *expB = tmp->next[0]->val;
    tmp = tmp->next[0];
    double *expC = tmp->next[0]->val;
    tmp = tmp->next[0];

    TEST_ASSERT_EQUAL_PTR(expA, a);
    TEST_ASSERT_EQUAL_PTR(expB, b);
    TEST_ASSERT_EQUAL_PTR(expC, c);
    TEST_ASSERT_NULL(tmp->next[0]);
}

static void test_add_one_element_char(void) {
    char *input = {&c1};

    Skiplist *list = initSkiplist(list, 1, compar_char);
    addItem(list, (void *)input);
    char *expected = (char *)searchSkipList(list, (void *)input);
    TEST_ASSERT_EQUAL_PTR(expected, input);
}

static void test_add_three_elements_char(void) {
    char *a = {&c1};
    char *b = {&c2};
    char *c = {&c3};

    Skiplist *list = initSkiplist(list, 1, compar_char);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    char *expA = (char *)searchSkipList(list, (void *)a);
    char *expB = (char *)searchSkipList(list, (void *)b);
    char *expC = (char *)searchSkipList(list, (void *)c);

    TEST_ASSERT_EQUAL_CHAR(*expA, *a);
    TEST_ASSERT_EQUAL_CHAR(*expB, *b);
    TEST_ASSERT_EQUAL_CHAR(*expC, *c);
}

static void test_order_three_elements_char(void) {
    char *a = {&c1};
    char *b = {&c2};
    char *c = {&c3};

    Skiplist *list = initSkiplist(list, 1, compar_char);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    Node *tmp = list->header;
    char *expA = tmp->next[0]->val;
    tmp = tmp->next[0];
    char *expB = tmp->next[0]->val;
    tmp = tmp->next[0];
    char *expC = tmp->next[0]->val;
    tmp = tmp->next[0];

    TEST_ASSERT_EQUAL_PTR(expA, a);
    TEST_ASSERT_EQUAL_PTR(expB, b);
    TEST_ASSERT_EQUAL_PTR(expC, c);
    TEST_ASSERT_NULL(tmp->next[0]);
}

static void test_add_one_element_string(void) {
    char *input = strdup("abaco");

    Skiplist *list = initSkiplist(list, 1, compar_char);
    addItem(list, (void *)input);
    char *expected = (char *)searchSkipList(list, (void *)input);
    TEST_ASSERT_EQUAL_PTR(expected, input);
}

static void test_add_three_elements_string(void) {
    char *a = strdup("abaco");
    char *b = strdup("balestra");
    char *c = strdup("casa");

    Skiplist *list = initSkiplist(list, 1, compar_string);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    char *expA = (char *)searchSkipList(list, (void *)a);
    char *expB = (char *)searchSkipList(list, (void *)b);
    char *expC = (char *)searchSkipList(list, (void *)c);

    TEST_ASSERT_EQUAL_STRING(expA, a);
    TEST_ASSERT_EQUAL_STRING(expB, b);
    TEST_ASSERT_EQUAL_STRING(expC, c);
}

static void test_order_three_elements_string(void) {
    char *a = strdup("abaco");
    char *b = strdup("balestra");
    char *c = strdup("casa");

    Skiplist *list = initSkiplist(list, 1, compar_string);

    addItem(list, (void *)a);
    addItem(list, (void *)b);
    addItem(list, (void *)c);

    Node *tmp = list->header;
    char *expA = tmp->next[0]->val;
    tmp = tmp->next[0];
    char *expB = tmp->next[0]->val;
    tmp = tmp->next[0];
    char *expC = tmp->next[0]->val;
    tmp = tmp->next[0];

    TEST_ASSERT_EQUAL_PTR(expA, a);
    TEST_ASSERT_EQUAL_PTR(expB, b);
    TEST_ASSERT_EQUAL_PTR(expC, c);
    TEST_ASSERT_NULL(tmp->next[0]);
}

int main(int argc, char const *argv[])
{
    UNITY_BEGIN();
    RUN_TEST(test_add_one_element_int);
    RUN_TEST(test_add_three_elements_int);
    RUN_TEST(test_order_three_elements_int);
    RUN_TEST(test_add_one_element_double);
    RUN_TEST(test_add_three_elements_double);
    RUN_TEST(test_order_three_elements_double);
    RUN_TEST(test_add_one_element_char);
    RUN_TEST(test_add_three_elements_char);
    RUN_TEST(test_order_three_elements_char);
    RUN_TEST(test_add_one_element_string);
    RUN_TEST(test_add_three_elements_string);
    RUN_TEST(test_order_three_elements_string);

    return UNITY_END();
}
