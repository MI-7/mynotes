/*
 *  test14.c
 *  set of bit functions
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

#define ARR_SIZE 100

void set_bit(char bit_array[], unsigned bit_number)
{
  bit_array[bit_number] = 1;
}

void clear_bit(char bit_array[], unsigned bit_number)
{
  bit_array[bit_number] = 0;
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
  if (value)
    bit_array[bit_number] = 1;
  else
    bit_array[bit_number] = 0;
}

int test_bit(char bit_array[], unsigned bit_number)
{
  if (bit_array[bit_number])
    return 1;
  else
    return 0;
}

void print_bit_array(char bit_array[], int n)
{
  for (int i = 0; i < n; i++)
  {
	if (bit_array[i] == 1)
	  printf("1");
	else
	  printf("0");
  }
  printf("\n");
}

void test14(void)
{
  char bit_array[ARR_SIZE];
  int r;

  srand(time(NULL));
  for (int i = 0; i < ARR_SIZE; i++)
  {
    r = rand();
    bit_array[i] = r % 2;
  }

  print_bit_array(bit_array, ARR_SIZE);

  set_bit(bit_array, 0);
  set_bit(bit_array, 1);
  set_bit(bit_array, 2);
  set_bit(bit_array, 3);
  set_bit(bit_array, 4);
  print_bit_array(bit_array, ARR_SIZE);

  clear_bit(bit_array, 0);
  clear_bit(bit_array, 1);
  clear_bit(bit_array, 2);
  clear_bit(bit_array, 3);
  clear_bit(bit_array, 4);
  print_bit_array(bit_array, ARR_SIZE);

  assign_bit(bit_array, 5, 88);
  assign_bit(bit_array, 6, 0);
  assign_bit(bit_array, 7, 99);
  print_bit_array(bit_array, ARR_SIZE);
}
