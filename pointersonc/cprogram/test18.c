/*
 * test18.c
 * Sieve of Eratosthenes, algorithm to find prime numbers.
 *  Created on: 2017年12月30日
 *      Author: chenliang
 */

#include "test.h"

#define INT_MODE

#ifdef INT_MODE
#define UP_LIMIT UINT_MAX / 4
typedef unsigned int PRIME_INT_TYPE;
#endif

#ifdef LONG_MODE
#define UP_LIMIT ULONG_MAX
typedef unsigned long PRIME_INT_TYPE;
#endif

void sieve_of_eratosthenes(unsigned char primes[])
{
  for (PRIME_INT_TYPE i = 2; i <= UP_LIMIT; i++)
  {
	PRIME_INT_TYPE j = i;
    if (primes[i])
    {
      while ((j+=i) <= UP_LIMIT)
      {
        primes[j] = FALSE;
      }
    }
  }
}

void test18(void)
{
  unsigned char *primes = (unsigned char *) malloc(sizeof(unsigned char) * (UP_LIMIT + 1));
  PRIME_INT_TYPE i = 0;
  PRIME_INT_TYPE seg_prime_count = 0, total_prime_count = 0;

  while (i <= UP_LIMIT)
  {
    primes[i++] = TRUE;
  }
  primes[0] = primes[1] = FALSE;

  sieve_of_eratosthenes(primes);

  i = 1;
  while (i <= UP_LIMIT)
  {
    if (primes[i])
    {
      seg_prime_count++;
      total_prime_count++;
    }

    if (i % 10000 == 0)
    {
      printf("from %8d to %8d = %4d\n", i-10000, i, seg_prime_count);
      seg_prime_count = 0;
    }

    i++;
  }

  printf("total prime number = %d\n", total_prime_count);

  free(primes);
}
