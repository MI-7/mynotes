/*
 *  test15.c
 *  search for a string
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

char * find_char(char const *source, char const *chars)
{
  char *p = source;
  char const *q;

  if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
  {
    return NULL;
  }

  for (; *p != '\0'; p++)
  {
    for (q = chars; *q != '\0'; q++)
    {
      if (*p == *q)
        return p;
    }
  }

  return NULL;
}

void test15(void)
{
  char *source = "abcdefg";
  char *chars = "xyz";

  char *s = find_char(source, chars);

  if (s == NULL)
    printf("s is empty\n");
  else
    printf("s=%c\n", *s);
}
