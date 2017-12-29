/*
 *  test12.c
 *  remove blank spaces
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

void deblank(char string[])
{
  /*
  char *p = string, *q = p;

  while (*p != '\0')
  {
    if (*p != ' ')
    {
      if (p != q)
      {
        *q = *p;
        q++;
      }
      else
      {
        q++;
      }
    }
    p++;
  }

  *q = *p;
  */

  for (char *p=string, *q=string; *p != '\0'; p++)
  {
    if (*p != ' ')
    {
      if (p != q)
        *q = *p;

      q++;
    }
  }
}

void
test12(void)
{
  char s[] = "        a b       c  d         ";
  deblank(s);
  printf("s=%s\n", s);
}
