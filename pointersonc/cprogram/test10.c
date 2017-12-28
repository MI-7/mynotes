/*
 * test10.c
 *
 *  Created on: 2017年12月28日
 *      Author: leonchan
 */
#include <stdio.h>
#include "test.h"

void
test10(void)
{
  char inputs[1000];

  while (gets(inputs) != NULL)
  {
    printf("line=%s\n", inputs);
  }
}
