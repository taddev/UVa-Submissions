#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  puts ("Please enter a line of text.");

  char buffer[12];
  fgets(buffer, 12, stdin);

  int length = 0;
  length = strlen(buffer);
  //buffer[length-1] = '\0';

  char *end;
  int i = (int) strtol(buffer, &end, 10);

  printf("Number: %d\nRemainder: %s", i, end);

  return 0;
}