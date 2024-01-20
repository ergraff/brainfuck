#ifndef _STDIO_H
#include <stdio.h>
#endif

#include "instructions.h"

// Move right
void right(char *p)
{
  ++p;
}

// Move left
void left(char *p)
{
  --p;
}

// Increment cell
void inc(char *p)
{
  ++*p;
}

// Decrement cell
void dec(char *p)
{
  --*p;
}

// Output cell
void out(char *p)
{
  printf("Out: %d (dec), %c (ascii)\n", *p);
}

// Read input to cell
void in(char *p)
{
  scanf("%c", p);
}

// TODO
// Brackets
void bracket(char *p)
{

}
