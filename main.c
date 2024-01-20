#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

// Lazy
#define MAX_PROG_LEN 1000

#define MEMORY_SIZE 30000

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
    // Too many arguments
    printf("Only one argument is expected!\n");
    return 1;
  }

  // DEBUG print argv
  for (int i = 0; i < argc; i++)
  {
    printf("argv[%d]: %s\n", i, argv[i]);
  }

  // Open file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Error opening file '%s'!\n", argv[1]);
    return 1;
  }

  // Initialize program string and memory pointers
  char *code =  (char*) malloc(MAX_PROG_LEN + 1);
  char *p = (char*) malloc(MEMORY_SIZE);
  
  // Read content of program file to string
  char *c = code;
  char temp;
  while((temp = (char) fgetc(file)) != EOF)
  {
    // Filter for valid characters
    if(temp == '>' ||
       temp == '<' ||
       temp == '+' ||
       temp == '-' ||
       temp == '.' ||
       temp == ',' ||
       temp == '[' ||
       temp == ']')
    {
      *c = temp;
      c++;
    }
  }

  // DEBUG print program
  printf("\nDEBUG Program: %s\n", code); // DEBUG

  // Run program
  printf("DEBUG Output:\n"); // DEBUG
  while(*code)
  {
    // printf("DEBUG Current: %c\n", *code); // DEBUG

    // Read instruction
    read_instruction(&code, &p);
    // printf("DEBUG *code = '%c'\n", *code); // DEBUG

    // Increment to next instruction
    code++;
  }

  printf("DEBUG Program end\n"); // DEBUG
}
