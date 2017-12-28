#include <stdio.h>
#include "test.h"

void
test8(void)
{
  int a, b, c, d, e, f, g;
  int ch;
  g = scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  
  if (g != 6)
  {
    printf("input is invalid\n");
    return;
  }
  
  printf("%d,%d,%d,%d,%d,%d\n", a, b, c, d, e, f);

  while( (ch = getchar()) != EOF  && ch != '\n')
    printf("%c\n", ch);

  return;
}
