#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// should be void *car
typedef struct cell {
  char car;
  struct cell *cdr;
} cell;

cell* new_cell(char token)
{
  cell* c = malloc(sizeof(cell));
  c->car = token;
  c->cdr = NULL;
  return c;
}

cell* append(char token, cell* c)
{
  cell *cdr = NULL;
  cell *cur = NULL;

  if (c == NULL) {
    c = new_cell(token);
    return c;
  } else {
    cur = c;
    cdr = c->cdr;
    for (;;) {
      if (cdr == NULL) {
	cdr = new_cell(token);
        cur->cdr = cdr;
	return c;
      }
      cur = cdr;
      cdr = cdr->cdr;
    }
  }
}

cell* parse(const char* expr)
{
  char token;
  bool done = false;

  int i = 0;
  int nLeftParen = 0;
  int nRightParen = 0;

  cell* list = NULL;
  
  while (!done) {
    token = expr[i];;
    switch(token) {
    case '(':
      list = append('(', list);
      nLeftParen++;
      i++;
      break;
    case ')':
      list = append(')', list);
      nRightParen++;
      i++;
      if (nLeftParen == nRightParen)
        done = true;
      break;
    default:
      list = append(token, list);
      i++;
      break;
    }
  }

  return list;
}

int main(void)
{
  const char *expression = "(* (+ 1 2) 4)";

  cell *list = NULL;
  cell *cur = NULL;

  list = parse(expression);

  cur = list;
  while (cur != NULL) {
    printf("%c", cur->car);
    cur = cur->cdr;
  }

  return EXIT_SUCCESS;
}
