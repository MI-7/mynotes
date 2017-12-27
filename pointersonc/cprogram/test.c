#include <stdio.h>

somefunc(x)
{
  return x+1;
}

int
main(void)
{
  FILE *fptr;
  int const asize = 5;
  unsigned char ch_buffer[asize];
  unsigned char ch;
  short int i = 0;
  char *s = "Hello";
  unsigned a;
  
  if ((fptr = fopen("c:\\users\\lchen4\\desktop\\temp\\Edit3", "r")) == NULL)
  {
    printf("file read error");
    exit(1);
  }
  
  while(!feof(fptr))
  {
    fread(&ch, sizeof (unsigned char), 1, fptr);
    printf("%X..%d..", ch, ch);
    
    if (i < 5)
    {
    	ch_buffer[i] = ch;
      i ++;
    }
  }
  
  if (ch_buffer[0] == 0xEF && ch_buffer[1] == 0xBB && ch_buffer[2] == 0xBF)
  {
    printf("\nthis file is encoded in utf-8");
  }
  
  /*wchar_t t = 0x0444;
  printf("\nwchar_t size=%d, str=%S,,,,,now what?", sizeof(wchar_t), &t);
  */
  
  fclose(fptr);
  /*s[1] = 'x';*/
  printf("\nsomething");
  goto abc;
  abc: printf("\n%s", s);
  abc: printf("something");
}