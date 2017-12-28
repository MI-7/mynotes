#include <stdio.h>
#include "test.h"

void
test4(void)
{
  char a[] = "abcd";
  *(a+1) = 'c';
  printf("a=%s\n", a);
}
