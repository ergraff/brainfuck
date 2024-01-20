#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define ARG_CODE_PTR char **code
#define ARG_MEM_PTR char **mem
#define CODE_PTR code
#define MEM_PTR mem
#define CODE_VAL **code
#define MEM_IN_PTR *mem
#define MEM_VAL **mem
#define MEM_RIGHT ++*mem
#define MEM_LEFT --*mem
#define MEM_INC ++**mem
#define MEM_DEC --**mem

#define RIGHT '>'
#define LEFT '<'
#define INC '+'
#define DEC '-'
#define OUT '.'
#define IN ','
#define L_BRACK '['
#define R_BRACK ']'

void right(ARG_MEM_PTR);
void left(ARG_MEM_PTR);
void inc(ARG_MEM_PTR);
void dec(ARG_MEM_PTR);
void out(ARG_MEM_PTR);
void in(ARG_MEM_PTR);
void bracket_left(ARG_CODE_PTR, ARG_MEM_PTR);
void bracket_right(ARG_CODE_PTR, ARG_MEM_PTR);
void read_instruction(ARG_CODE_PTR, ARG_MEM_PTR);

#endif
