/*
 *  test13.c
 *  reverse bit by bit
 *  00000000000000000000000000011001 ->
 *  10011000000000000000000000000000 -> return integer
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

void print_bits(unsigned int value)
{
  for (int i = sizeof(value) * 8 - 1; i >= 0 ; i--)
  {
    if (value & (1 << i))
    {
      printf("1");
    }
    else
      printf("0");
  }
  printf("\n");
}

unsigned int reverse_bits(unsigned int value)
{
  unsigned int r = 0;
  int size = sizeof(value) * 8;

  for (int i = 0; i < size; i++)
  {
    if (value & (1 << i))
    {
      r = r | (1 << (size - 1 - i));
      print_bits(r);
    }
  }

  return r;
}

void test13(void)
{
  unsigned int v = 25;
  unsigned int r = reverse_bits(v);
  printf("r=%u\n", r);
}
