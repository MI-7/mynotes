/*
 * test.h
 *
 *  Created on: 2017年12月28日
 *      Author: leonchan
 */

#ifndef POINTERSONC_CPROGRAM_TEST_H_
#define POINTERSONC_CPROGRAM_TEST_H_

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define NULL  0
#define NUL   '\0'
#define TRUE  1
#define FALSE 0

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);
void test13(void);

void copy_n(char dst[], char src[], int n);
int substr (char dst[], char src[], int start, int len);
void deblank(char string[]);
unsigned int reverse_bits(unsigned int value);

/* bit functions */
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
void print_bit_array(char bit_array[], int n);
void test14(void);

char * find_char(char const *source, char const *chars);
void test15(void);

int del_substr( char *str, char const *substr );
void test16(void);

void reverse_string(char *string);
void test17(void);

void sieve_of_eratosthenes(unsigned char primes[]);
void test18(void);

#endif /* POINTERSONC_CPROGRAM_TEST_H_ */
