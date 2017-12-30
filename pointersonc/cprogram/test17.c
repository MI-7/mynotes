/*
 * test17.c
 *
 *  Created on: 2017年12月30日
 *      Author: chenliang
 */

#include "test.h"

void reverse_string(char *string)
{
  char *p = string, *q = string;

  while (*q != NUL && *(q+1) != NUL)
    q++;

  for (char c; p < q; p++, q--)
    c = *p, *p = *q, *q = c;
}

void test17(void)
{
  char s[] = "abcdefg";
  printf("s=%s,p=%p\n", s, s);
  reverse_string(s);
  printf("s=%s,p=%p\n", s, s);
}
