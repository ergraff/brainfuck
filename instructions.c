#ifndef _STDIO_H
#include <stdio.h>
#endif

#include "instructions.h"

// Move right
void right(ARG_MEM_PTR)
{
  MEM_RIGHT;
}

// Move left
void left(ARG_MEM_PTR)
{
  MEM_LEFT;
}

// Increment cell
void inc(ARG_MEM_PTR)
{
  MEM_INC;
}

// Decrement cell
void dec(ARG_MEM_PTR)
{
  MEM_DEC;
}

// Output cell
void out(ARG_MEM_PTR)
{
  printf("DEBUG Out: %d\t(dec)\t%c\t(ascii)\n", MEM_VAL, MEM_VAL); // DEBUG
  // printf("%c", MEM_VAL);
}

// Read input to cell
void in(ARG_MEM_PTR)
{
  scanf("%c", MEM_IN_PTR);
}

// Left bracket
void bracket_left(ARG_CODE_PTR, ARG_MEM_PTR)
{
  if(MEM_VAL == 0)
  {
    // printf("DEBUG Moving forward to matching bracket\n"); // DEBUG
    // Go to next matching bracket
    int counter = 1;
    while ( CODE_VAL != R_BRACK && counter != 0 )
    {
      ++*code;
      // printf("DEBUG %c\n", **code); // DEBUG
      if(CODE_VAL == L_BRACK) counter ++;
      if(CODE_VAL == R_BRACK) counter --;
    }
    // printf("DEBUG Found matching bracket ']'. **code = '%c'\n", **code); // DEBUG
  }
}

// Right bracket
void bracket_right(ARG_CODE_PTR, ARG_MEM_PTR)
{
  if(MEM_VAL != 0)
  {
    // printf("DEBUG Moving back to matching bracket\n"); // DEBUG
    // Go to previous matching bracket
    int counter = 1;
    while( CODE_VAL != L_BRACK && counter != 0 )
    {
      // printf("DEBUG %c\n", **code); // DEBUG
      --*code;
      if(CODE_VAL == R_BRACK) counter++;
      if(CODE_VAL == L_BRACK) counter--;
    }
    // printf("DEBUG Found matching bracket '['. **code = '%c'\n", **code); // DEBUG
  }
}

// Read instruction
void read_instruction(ARG_CODE_PTR, ARG_MEM_PTR)
{
  // printf("DEBUG Reading: %c\n", CODE_VAL); // DEBUG
  switch(CODE_VAL)
  {
    case RIGHT:
      right(MEM_PTR);
      break;
    case LEFT:
      left(MEM_PTR);
      break;
    case INC:
      inc(MEM_PTR);
      break;
    case DEC:
      dec(MEM_PTR);
      break;
    case OUT:
      out(MEM_PTR);
      break;
    case IN:
      in(MEM_PTR);
      break;
    case L_BRACK:
      bracket_left(CODE_PTR, MEM_PTR);
      break;
    case R_BRACK:
      bracket_right(CODE_PTR, MEM_PTR);
      break;
  }
}
