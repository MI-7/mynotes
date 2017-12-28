#include <stdio.h>
#include "test.h"

void
test2(void)
{
  char *c = "abc\60";
  char *c2 = "\0614";
  /*
  char *c21 = "\x314defYYYhijkl";
  char c4 = "\x310000456";
  */
  char c3 = '\61';
  char c31 = '\x31';
  
  int d = '\160';
  int d2 = '\1160';
  /*
  int e = '\x1234';
  int f = '\x234';
  */
  int g = '\x34';
  
  printf("c=%s_c2=%s_c3=%c_c31=%c\n", c, c2, c3, c31);
  printf("d=%d_d2=%d_g=%d\n", d, d2, g);
  
  
  int *x = &d;
  
  for( int i = sizeof(d) * 8 - 1; i >= 0; i-- )
  {
    if (*x & (1 << i))
      printf("1");
    else
      printf("0");
  }
}
