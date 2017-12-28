#include <stdio.h>
#include "test.h"

void
test3(void)
{
  enum coin {PENNY, NICKEL, OTHER};
  char* coinNames[] = {[PENNY] = "Penny", [NICKEL] = "Nickel", [OTHER] = "Other", ['0'] = "Hello"};
  
  enum coin a = PENNY;
  
  printf("a=%d\n", a);
  printf("a=%s\n", coinNames[a]);
  printf("a=%s\n", coinNames[48]);
}
