#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions.h"

#define MAX_PROG_LEN 1000
#define MEMORY_SIZE 30000

int main(int argc, char **argv)
{
  // Check arguments
  if(argc < 2)
  {
    // No arguments
    printf("No argument was given!\n");
    return 1;
  }
  if(argc > 2)
  {
    // Too many arguments
    printf("Only one argument is expected!\n");
    return 1;
  }

  // --help message
  if(strcmp(argv[1], "--help") == 0)
  {
    printf("use: (./)brainfuck <path>\n\nExample:\n(./)brainfuck examples/helloworld1.bf\n");
    return 0;
  }

  // Open file
  FILE *file = fopen(argv[1], "r");
  if(file == NULL)
  {
    printf("Error opening file '%s'!\n", argv[1]);
    return 1;
  }

  // Initialize program string and memory pointers
  char *code =  (char*) malloc(MAX_PROG_LEN + 1);
  char *mem = (char*) malloc(MEMORY_SIZE);
  
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

  // Run program
  while(*code)
  {
    // Read instruction
    read_instruction(&code, &mem);

    // Increment to next instruction
    code++;
  }

  return 0;
}
