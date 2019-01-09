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

void append(char token, cell** l)
{
  cell **cdr = l;

  if (*l == NULL) {
    *l = new_cell(token);
    return;
  } else {
    cdr = &((*l)->cdr);
    for (;;) {
      if ((*cdr) == NULL) { 
	*cdr = new_cell(token);
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

typedef struct char_token {
	char c;
	struct char_token* next;
} char_token;

char_token* init() {
	char_token* token = malloc(sizeof(char_token));
	token->next = NULL;
	return token;
}

char_token* charToken(char c) {
	char_token* res = init();
	res->c = c;
	return res;
}

int izmars_main(void)
{  
  const char* code = "(lambda () \"Hello World\")";

  char_token *head = charToken(code[0]);
  char_token *prev = head;

  const size_t length = strlen(code);
  for (int i = 1; i < length; i++) {
    char_token *curr = charToken(code[i]);
    prev->next = curr;
    prev = curr;
  }

  char_token* curr = head;

  while (curr != NULL) {
    printf("%c", curr->c);
    curr = curr->next;
  }

  return 0;
}

int main(void)
{
  cell *l = NULL;

  append('(', &l);
  append('*', &l);
  append(')', &l);

  cell* curr = l;
  while (curr != NULL) {
    printf("%c", curr->car);
    curr = curr->cdr;
  }

  // izmars_main();
  
}
