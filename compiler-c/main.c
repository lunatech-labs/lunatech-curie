#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// should be void *car
typedef struct list {
  char car;
  struct list *cdr;
} list;

void append(char token, struct list** l)
{
  list *cell = NULL;
  list **cdr = l;

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

int main(void)
{
  /* list *l = NULL; */

  /* append('(', &l); */
  /* append('*', &l); */
  /* append(')', &l); */

  /* printf("%c", l->cdr->cdr->car); */


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
