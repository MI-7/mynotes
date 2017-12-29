/*
 * find prime numbers
 */
#include <stdio.h>
#include "test.h"

unsigned short
is_prime(int n)
{
  int i;

  for (i = 2; i <= n; i++)
  {
    if (n % i == 0 && n != i)
    {
      return 0;
    }
  }

  return 1;
}

void
test7(void)
{
  int max_to_test;
  int i;

  printf("enter max number to search for primes:");
  if (scanf("%d", &max_to_test) != 1)
  {
    printf("invalid input, using 1000 as input\n");
    max_to_test = 1000;
  }

  for (i = 2; i <= max_to_test; i++)
  {
    if (is_prime(i))
    {
      printf("found prime:%d\n", i);
    }
  }
}
