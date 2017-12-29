/*
 *  test16.c
 *  deletes a portion of a string
 *  Created on: 2017年12月29日
 *      Author: chenliang
 */

#include "test.h"

int del_substr( char *str, char const *substr )
{
  char *p, *q;

  for (int i = 0; i < strlen(str) - strlen(substr) + 1; i++)
  {
    for (p = str, q = substr; *p != '\0'; p++)
    {
    }
  }

  return 0;
}

void test16(void)
{

}
