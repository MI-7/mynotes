#include <stdio.h>

int
main(void)
{
  char a[] = "abcd";
  *(a+1) = 'c';
  printf("a=%s\n", a);
}