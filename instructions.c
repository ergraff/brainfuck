#ifndef _STDIO_H
#include <stdio.h>
#endif

#include "instructions.h"

// Move right
void right(char **p)
{
  ++*p;
}

// Move left
void left(char **p)
{
  --*p;
}

// Increment cell
void inc(char **p)
{
  ++**p;
}

// Decrement cell
void dec(char **p)
{
  --**p;
}

// Output cell
void out(char **p)
{
  printf("DEBUG Out: %d (dec), %c (ascii)\n", **p, **p); // DEBUG
  // printf("%c\n", **p);
}

// Read input to cell
void in(char **p)
{
  scanf("%c", *p);
}

// TODO
// Left bracket
void bracket_left(char **code, char **p)
{
  if (**p == 0)
  {
    // printf("DEBUG Moving forward to matching bracket\n"); // DEBUG
    // Go to next matching bracket
    int counter = 1;
    while ( **code != ']' && counter != 0 )
    {
      ++*code;
      // printf("DEBUG %c\n", **code); // DEBUG
      if (**code == '[') counter ++;
      if (**code == ']') counter --;
    }
    // printf("DEBUG Found matching bracket ']'. **code = '%c'\n", **code); // DEBUG
  }
}

// TODO
// Right bracket
void bracket_right(char **code, char **p)
{
  if (**p != 0)
  {
    // printf("DEBUG Moving back to matching bracket\n"); // DEBUG
    // Go to previous matching bracket
    int counter = 1;
    while ( **code != '[' && counter != 0 )
    {
      // printf("DEBUG %c\n", **code); // DEBUG
      --*code;
      if (**code == ']') counter++;
      if (**code == '[') counter--;
    }
    // printf("DEBUG Found matching bracket '['. **code = '%c'\n", **code); // DEBUG
  }
}
