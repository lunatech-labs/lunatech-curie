#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// should be void *car
struct list {
  char car;
  struct list *cdr;
};

void append(char token, struct list** l)
{
  struct list *cell = NULL;
  struct list **cdr = l;

  cell = malloc(sizeof(struct list));
  cell->car = token;
  cell->cdr = NULL;

  if (*l == NULL) {
    *l = cell;
    return;
  } else {
    cdr = &((*l)->cdr);
    for (;;) {
      if ((*cdr) == NULL) { 
	*cdr = cell;
	return;
      }
      cdr = &((*cdr)->cdr);
    }
  }
}

void parse()
{
  char token;
  bool done = false;

  char buf[1000] = "(* (+ 1 2) 4)";
  int i = 0;
  int nLeftParen = 0;
  int nRightParen = 0;
  
  while (!done) { 
    token = buf[i];; 
    switch(token) { 
    case '(': 
      nLeftParen++; 
      i++; 
      break; 
    case ')': 
      nRightParen++; 
      i++; 
      if (nLeftParen == nRightParen) 
        done = true; 
      break; 
    case ' ': 
      i++; 
      break; 
    default: 
      i++; 
      break; 
    } 
  } 
}

int main(void)
{
  struct list *l = NULL;

  append('(', &l);
  append('*', &l);
  append(')', &l);

  printf("%c", l->cdr->cdr->car);
  
}
