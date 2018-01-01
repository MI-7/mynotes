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

#define F_UP_LIMIT 1000

int get_digit_num(unsigned long l)
{
  if (l < 10)
    return 1;
  else if (l <= 99)
    return 2;
  else if (l <= 999)
    return 3;
  else if (l <= 9999)
    return 4;
  else if (l < 99999)
    return 5;
  else if (l < 999999)
    return 6;
  else if (l < 9999999)
    return 7;
  else if (l < 99999999)
    return 8;
  else if (l < 999999999)
    return 9;
  else if (l < 9999999999)
    return 10;
  else if (l < 99999999999)
    return 11;
  else if (l < 999999999999)
    return 12;
  else if (l < 9999999999999)
    return 13;
}

int initialize_file()
{
  FILE *f;
  char *p;
  char *postfix = "=0\n";

  if(!(f = fopen("./primes", "w"))) //open the file for updating
	return -1;

  for (unsigned long l = 2; l < F_UP_LIMIT; l++)
  {
    p = (char *) malloc(sizeof(char) * (get_digit_num(l)+2));
    sprintf(p, "%ld%s", l, postfix);
    fputs(p, f);
    free(p);
  }

  fclose(f);

  return 0;
}

void sieve_of_eratosthenes_with_files()
{
  FILE *f;
  char *p;
  char *true_post = "=1";
  char *false_post = "=0";

  if (initialize_file() == 0)
    printf("initialization done\n");

  if(!(f = fopen("./primes", "w"))) //open the file for updating
	return;

  for (unsigned long i = 2; i <= UP_LIMIT; i++)
  {
    unsigned long j = i;

    p = (char *) malloc(sizeof(char) * get_digit_num(j));
    /*
    if (primes[i])
    {
      while ((j+=i) <= UP_LIMIT)
      {
        primes[j] = FALSE;
      }
    }
    */
    free(p);
  }

  fclose(f);
}

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
