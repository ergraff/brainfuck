#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions.h"
/* Lazy early test */
#define MAX_PROG_LEN 1000

int main(int argc, char **argv)
{
  // Check arguments
  if (argc < 2)
  {
    // No arguments
    printf("No argument was given!\n");
    return 1;
  }
  if (argc > 2)
  {
    // Too manu arguments
    printf("Only one argument is expected!\n");
    return 1;
  }

  // DEBUG print argv
  for (int i = 0; i < argc; i++)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  // Read file
  FILE *fptr = fopen(argv[1], "r");
  if (fptr == NULL)
  {
    printf("Error opening file '%s'!\n", argv[1]);
    return 1;
  }

  // DEBUG print content of file
  size_t maxl = 256;
  char line[maxl];
  char content[MAX_PROG_LEN]; 
  while(fgets(line, maxl, fptr))
  {
    strcat(content, line);
  };
  printf("%s", content);

  // DEBUG check includes
  right();
  left();
  inc();
  dec();
  out();
  in();
  bracket();

  return 0;
}
