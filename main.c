#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("use: brainfuck <path>\n\nExample:\nbrainfuck examples/helloworld1.bf\n");
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
    switch(*code)
    {
      case '>':
        // Move right
        ++mem;
        break;
      case '<':
        // Move left
        --mem;
        break;
      case '+':
        // Increment cell
        ++*mem;
        break;
      case '-':
        // Decrement cell
        --*mem;
        break;
      case '.':
        // Output cell
        printf("%c", *mem);
        break;
      case ',':
        // Read input to cell
        scanf("%c", mem);
        break;
      case '[':
        if(*mem == 0)
        // Go to next matching bracket ']'
        {
          int counter = 1;
          while (*code != ']' || counter != 0 )
          {
            ++code;
            if(*code == '[') counter++;
            if(*code == ']') counter--;
          }
        }
        break;
      case ']':
        if(*mem != 0)
        // Go to previous matching bracket '['
        {
          int counter = 1;
          while(*code != '[' || counter != 0 )
          {
            --code;
            if(*code == ']') counter++;
            if(*code == '[') counter--;
          }
        }
        break;
    }

    // Increment to next instruction
    ++code;
  }

  return 0;
}
