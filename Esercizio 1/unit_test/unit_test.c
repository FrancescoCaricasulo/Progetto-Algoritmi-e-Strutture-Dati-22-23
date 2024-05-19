#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "unity_internals.h"
#include "../lib/library.h"
#include "../misc/compar.h"
#include <string.h>

static int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;

static double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;

void setUp(void)
{
    v1 = 1;
    v2 = 2;
    v3 = 3;
    v4 = 4;
    v5 = 5;
    v6 = 6;
    v7 = 7;
    v8 = 8;
    v9 = 9;
    v10 = 10;

    d1 = 1.0;
    d2 = 2.0;
    d3 = 3.0;
    d4 = 4.0;
    d5 = 5.0;
    d6 = 6.0;
    d7 = 7.0;
    d8 = 8.0;
    d9 = 9.0;
    d10 = 10.0;
}

void tearDown(){

}

static void test_one_element_int_k_min(void) {
    int *input = {&v1};
    int *expected = {&v1};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(int), 0, compar_int);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 1);
}

static void test_one_element_int_k_max(void) {
    int *input = {&v1};
    int *expected = {&v1};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(int), 1, compar_int);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 1);
}

static void test_ten_element_int_k_min(void){
    int input[10] = {v10, v9, v8, v7, v6, v5, v4, v3, v2, v1};
    int expected[10] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(int), 0, compar_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, input, 10);
}

static void test_ten_element_int_k_max(void){
    int input[10] = {v10, v9, v8, v7, v6, v5, v4, v3, v2, v1};
    int expected[10] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(int), 10, compar_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, input, 10);
}

static void test_ten_element_int_k_mid(void){
    int input[10] = {v10, v9, v8, v7, v6, v5, v4, v3, v2, v1};
    int expected[10] = {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(int), 5, compar_int);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, input, 10);
}

static void test_one_element_double_k_min(void) {
    double *input = {&d1};
    double *expected = {&d1};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(double), 0, compar_double);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 1);
}

static void test_one_element_double_k_max(void) {
    double *input = {&d1};
    double *expected = {&d1};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(double), 1, compar_double);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 1);
}

static void test_ten_element_double_k_min(void){
    double input[10] = {d10, d9, d8, d7, d6, d5, d4, d3, d2, d1};
    double expected[10] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(double), 0, compar_double);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 10);
}

static void test_ten_element_double_k_max(void){
    double input[10] = {d10, d9, d8, d7, d6, d5, d4, d3, d2, d1};
    double expected[10] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(double), 10, compar_double);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 10);
}

static void test_ten_element_double_k_mid(void){
    double input[10] = {d10, d9, d8, d7, d6, d5, d4, d3, d2, d1};
    double expected[10] = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(double), 5, compar_double);
    TEST_ASSERT_EQUAL_PTR_ARRAY(expected, input, 10);
}

static void test_one_element_char_k_min(void) {
    char input[1] = {'a'};
    char expected[1] = {'a'};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(char), 0, compar_char);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 1);
}

static void test_one_element_char_k_max(void) {
    char input[1] = {'a'};
    char expected[1] = {'a'};
    merge_binary_insertion_sort((void *)input, 0, 1, sizeof(char), 1, compar_char);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 1);
}

static void test_ten_element_char_k_min(void) {
    char input[10] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char expected[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(char), 0, compar_char);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

static void test_ten_element_char_k_max(void) {
    char input[10] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char expected[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(char), 10, compar_char);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

static void test_ten_element_char_k_mid(void) {
    char input[10] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    char expected[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    merge_binary_insertion_sort((void *)(&input[0]), 0, 9, sizeof(char), 5, compar_char);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

static void test_one_element_chars_k_min(void) {
    char input[1][10];
    char expected[1][10];

    memcpy(input[0], "abaco", 10 * sizeof(char));

    memcpy(expected[0], "abaco", 10 * sizeof(char));
    
    merge_binary_insertion_sort((void **)(&input[0]), 0, 1, 10 * sizeof(char), 0, compar_string);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 1);
}

static void test_one_element_chars_k_max(void) {
    char input[1][10];
    char expected[1][10];

    memcpy(input[0], "abaco", 10 * sizeof(char));

    memcpy(expected[0], "abaco", 10 * sizeof(char));
    
    merge_binary_insertion_sort((void **)(&input[0]), 0, 1, 10 * sizeof(char), 1, compar_string);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 1);
}

static void test_ten_element_chars_k_min(void) {
    char input[10][10];
    char expected[10][10];

    memcpy(input[0], "zattera", 10 * sizeof(char));
    memcpy(input[1], "casa", 10 * sizeof(char));
    memcpy(input[2], "abaco", 10 * sizeof(char));
    memcpy(input[3], "lettera", 10 * sizeof(char));
    memcpy(input[4], "manuale", 10 * sizeof(char));
    memcpy(input[5], "signore", 10 * sizeof(char));
    memcpy(input[6], "tastiera", 10 * sizeof(char));
    memcpy(input[7], "computer", 10 * sizeof(char));
    memcpy(input[8], "nave", 10 * sizeof(char));
    memcpy(input[9], "tappeto", 10 * sizeof(char));

    memcpy(expected[0], "abaco", 10 * sizeof(char));
    memcpy(expected[1], "casa", 10 * sizeof(char));
    memcpy(expected[2], "computer", 10 * sizeof(char));
    memcpy(expected[3], "lettera", 10 * sizeof(char));
    memcpy(expected[4], "manuale", 10 * sizeof(char));
    memcpy(expected[5], "nave", 10 * sizeof(char));
    memcpy(expected[6], "signore", 10 * sizeof(char));
    memcpy(expected[7], "tappeto", 10 * sizeof(char));
    memcpy(expected[8], "tastiera", 10 * sizeof(char));
    memcpy(expected[9], "zattera", 10 * sizeof(char));
    
    merge_binary_insertion_sort((void **)(&input[0]), 0, 9, 10 * sizeof(char), 0, compar_string);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

static void test_ten_element_chars_k_max(void) {
    char input[10][10];
    char expected[10][10];

    memcpy(input[0], "zattera", 10 * sizeof(char));
    memcpy(input[1], "casa", 10 * sizeof(char));
    memcpy(input[2], "abaco", 10 * sizeof(char));
    memcpy(input[3], "lettera", 10 * sizeof(char));
    memcpy(input[4], "manuale", 10 * sizeof(char));
    memcpy(input[5], "signore", 10 * sizeof(char));
    memcpy(input[6], "tastiera", 10 * sizeof(char));
    memcpy(input[7], "computer", 10 * sizeof(char));
    memcpy(input[8], "nave", 10 * sizeof(char));
    memcpy(input[9], "tappeto", 10 * sizeof(char));

    memcpy(expected[0], "abaco", 10 * sizeof(char));
    memcpy(expected[1], "casa", 10 * sizeof(char));
    memcpy(expected[2], "computer", 10 * sizeof(char));
    memcpy(expected[3], "lettera", 10 * sizeof(char));
    memcpy(expected[4], "manuale", 10 * sizeof(char));
    memcpy(expected[5], "nave", 10 * sizeof(char));
    memcpy(expected[6], "signore", 10 * sizeof(char));
    memcpy(expected[7], "tappeto", 10 * sizeof(char));
    memcpy(expected[8], "tastiera", 10 * sizeof(char));
    memcpy(expected[9], "zattera", 10 * sizeof(char));
    
    merge_binary_insertion_sort((void **)(&input[0]), 0, 9, 10 * sizeof(char), 10, compar_string);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

static void test_ten_element_chars_k_mid(void) {
    char input[10][10];
    char expected[10][10];

    memcpy(input[0], "zattera", 10 * sizeof(char));
    memcpy(input[1], "casa", 10 * sizeof(char));
    memcpy(input[2], "abaco", 10 * sizeof(char));
    memcpy(input[3], "lettera", 10 * sizeof(char));
    memcpy(input[4], "manuale", 10 * sizeof(char));
    memcpy(input[5], "signore", 10 * sizeof(char));
    memcpy(input[6], "tastiera", 10 * sizeof(char));
    memcpy(input[7], "computer", 10 * sizeof(char));
    memcpy(input[8], "nave", 10 * sizeof(char));
    memcpy(input[9], "tappeto", 10 * sizeof(char));

    memcpy(expected[0], "abaco", 10 * sizeof(char));
    memcpy(expected[1], "casa", 10 * sizeof(char));
    memcpy(expected[2], "computer", 10 * sizeof(char));
    memcpy(expected[3], "lettera", 10 * sizeof(char));
    memcpy(expected[4], "manuale", 10 * sizeof(char));
    memcpy(expected[5], "nave", 10 * sizeof(char));
    memcpy(expected[6], "signore", 10 * sizeof(char));
    memcpy(expected[7], "tappeto", 10 * sizeof(char));
    memcpy(expected[8], "tastiera", 10 * sizeof(char));
    memcpy(expected[9], "zattera", 10 * sizeof(char));
    
    merge_binary_insertion_sort((void **)(&input[0]), 0, 9, 10 * sizeof(char), 5, compar_string);

    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, input, 10);
}

int main(int argc, char const *argv[])
{
    UNITY_BEGIN();
    RUN_TEST(test_one_element_int_k_min);
    RUN_TEST(test_one_element_int_k_max);
    RUN_TEST(test_ten_element_int_k_min);
    RUN_TEST(test_ten_element_int_k_mid);
    RUN_TEST(test_ten_element_int_k_max);  
    RUN_TEST(test_one_element_double_k_min);
    RUN_TEST(test_one_element_double_k_max);
    RUN_TEST(test_ten_element_double_k_min);
    RUN_TEST(test_ten_element_double_k_mid);
    RUN_TEST(test_ten_element_double_k_max);
    RUN_TEST(test_one_element_char_k_min);
    RUN_TEST(test_one_element_char_k_max);
    RUN_TEST(test_ten_element_char_k_min);
    RUN_TEST(test_ten_element_char_k_max);
    RUN_TEST(test_ten_element_char_k_mid);
    RUN_TEST(test_one_element_chars_k_min);
    RUN_TEST(test_one_element_chars_k_max);
    RUN_TEST(test_ten_element_chars_k_min);
    RUN_TEST(test_ten_element_chars_k_max);
    RUN_TEST(test_ten_element_chars_k_mid);

    return UNITY_END();
}
