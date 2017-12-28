#include <stdio.h>
#include "test.h"

void copy_n(char dst[], char src[], int n)
{
  /* get the src length */
  int src_len = 0, copy_len = 0;
  char *p = src;
  
  while(*p++ != '\0')
    src_len ++;
  
  printf("src len=%d\n", src_len);
  
  copy_len = n;
  if (src_len < n)
  {
    copy_len = src_len;
  }

  for (int i = 0; i < copy_len; i++)
    dst[i] = src[i];
  
  if (copy_len < n)
  {
    dst[copy_len] = '\0';
  }
}

void
test9(void)
{
  char dst[] = "1234567890";
  char src[]="abcdefg";
  
  copy_n(dst, src, 8);
  
  printf("dst=%s_%c\n", dst, dst[9]);
}
