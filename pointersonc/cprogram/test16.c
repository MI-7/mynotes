/*
 *  test16.c
 *  deletes substring from original one
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

/* abcdefg  ->  abfg
 *   cde
 */
int del_substr( char *str, char const *substr )
{
  char *p, *q, *r;
  int len_diff = strlen(str) - strlen(substr);

  /* the maximum time comparisons could happen to search for substring */
  for (q=str; q - str <= len_diff; q++)
  {
    p = substr;
    r = q;

    while (*p++ == *q++ && *p != NUL)
      ;

    /* if we fall out of the loop cause we reached the end, this is a match */
    if (*p == NUL)
    {
      while (*r++ = *q++)
        ;

      return 1;
    }
  }

  return 0;
}

void test16(void)
{
  char str[] = "abcdefg";
  char *substr = "cdefgx";
  del_substr(str, substr);
  printf("str=%s\n", str);
}
