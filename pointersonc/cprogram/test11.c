/*
 *  test11.c
 *  take sub string
 *  Created on: 2017年12月28日
 *      Author: chenliang
 */

#include "test.h"

#define STRING_LEN 100

int substr (char dst[], char src[], int start, int len)
{
  int i;

  if (start < 0 || len < 0 || start >= strlen(src))
  {
    dst[0] = '\0';
    return 0;
  }

  for (i = 0; i < len  && src[i + start] != '\0'; i++)
  {
    dst[i] = src[i + start];
  }

  dst[i] = '\0';

  return strlen(dst);
}

void
test11(void)
{
  char dst[STRING_LEN];
  char src[] = "1234567890";

  int result = substr(dst, src, 8, 500);

  printf("dst=%s, dst len=%d\n", dst, result);
}
