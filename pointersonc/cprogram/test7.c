#include <stdio.h>

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

int
main(void)
{
  int max_to_test = 100;
  int i;

  for (i = 2; i <= max_to_test; i++)
  {
    if (is_prime(i))
    {
      printf("found prime:%d\n", i);
    }
  }

  return 0;
}
