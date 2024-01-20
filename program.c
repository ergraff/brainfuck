#ifndef _STDIO_H
#include <stdio.h>
#endif

#include "program.h"
#include "instructions.h"

void read_instruction(char c, char *p)
{
  // printf("Reading: %c\n", c); // DEBUG
  switch (c)
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
      bracket(p);
      break;
  }
  
}
