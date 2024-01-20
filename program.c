#ifndef _STDIO_H
#include <stdio.h>
#endif

#include "program.h"
#include "instructions.h"

void read_instruction(char **code, char **p)
{
  // printf("DEBUG Reading: %c\n", **code); // DEBUG
  switch (**code)
  {
    case '>':
      right(p);
      break;
    case '<':
      left(p);
      break;
    case '+':
      inc(p);
      break;
    case '-':
      dec(p);
      break;
    case '.':
      out(p);
      break;
    case ',':
      in(p);
      break;
    case '[':
      bracket_left(code, p);
      break;
    case ']':
      bracket_right(code, p);
      break;
  }
  
}
