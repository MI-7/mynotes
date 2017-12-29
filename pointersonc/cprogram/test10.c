/*
 *  test10.c
 *  print duplicated input as one
 *  Created on: 2017年12月28日
 *      Author: leonchan
 */
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "test.h"

void
test10(void)
{
  char input[128];
  char *old_input = NULL;
  short already_printed = 0;

  while (gets(input) != NULL)
  {
    if (old_input == NULL)
    {
      old_input = (char *) malloc(128 * sizeof(char));
      strcpy(old_input, input);
      continue;
    }

    if (!strcmp(input, old_input))
    {
      if (!already_printed)
      {
        printf("%s\n", input);
        already_printed = 1;
      }
    }
    else
    {
      already_printed = 0;
    }

    strcpy(old_input, input);
  }
}
