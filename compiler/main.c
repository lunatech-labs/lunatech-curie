#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int SYMBOL_LENGTH = 32;
const int NUMBER_LENGTH = 32;
const char LPAREN = '(';
const char RPAREN = ')';
const char SPACE = ' ';
const char MULT = '*';
const char PLUS = '+';

typedef struct cell {
    char* value;
    struct cell *next;
} cell;

cell* new_cell(const char* token)
{
    char* value = malloc(sizeof(char) * SYMBOL_LENGTH);
    cell* c = malloc(sizeof(cell));
    c->value = strcpy(value, token);
    c->next = NULL;
    return c;
}

cell* append(const char* token, cell* c)
{
    cell *next = NULL;
    cell *cur = NULL;

    if (c == NULL) {
	c = new_cell(token);
	return c;
    } else {
	cur = c;
	next = c->next;
	for (;;) {
	    if (next == NULL) {
		next = new_cell(token);
		cur->next = next;
		return c;
	    }
	    cur = next;
	    next = next->next;
	}
    }
}

cell* parse(const char* expr)
{
    char token, previous_token;
    bool done = false;
    char symbol[SYMBOL_LENGTH];
    int symbol_pos = -1;

    char number[NUMBER_LENGTH];
    int number_pos = -1;
  
    const char* lparen = "(";
    const char* rparen = ")";
    const char* mult = "*";
    const char* plus = "+";
    const char* space = " ";
  
    int i = 0;
    int nLeftParen = 0;
    int nRightParen = 0;

    cell* list = NULL;

    token = expr[0];
    previous_token = token;
    while (!done) {
	if (token == '\0') {
	    done = true;
	} else if (token == LPAREN) {
	    list = append(lparen, list);
	} else if (token == MULT) {
	    list = append(mult, list);
	} else if (token == PLUS) {
	    list = append(plus, list);
	} else if ((symbol_pos > -1) && isalnum(token)) {
	    symbol_pos++;
	    symbol[symbol_pos] = token;
	    symbol[symbol_pos + 1] = '\0';     
	} else if ((symbol_pos < 0) && isalpha(token)) {
	    if ((previous_token == LPAREN) || (previous_token == SPACE)) {
		symbol_pos = 0;
		symbol[symbol_pos] = token;
		symbol[symbol_pos + 1] = '\0';
	    } else {
		printf("token %c cannot follow token %c\n", token, previous_token);
	    }

	} else if ((number_pos < 0) && isdigit(token)) {
	    number_pos = 0;
	    number[number_pos] = token;
	    number[number_pos + 1] = '\0';
	} else if ((number_pos > -1) && isdigit(token)) {
	    number_pos++;
	    number[number_pos] = token;
	    number[number_pos + 1] = '\0';
	} else if (token == RPAREN) {
	    nRightParen++;
	    if (symbol_pos > -1) {
		list = append(symbol, list);
		symbol_pos = -1;
	    } else if (number_pos > -1) {
		list = append(number, list);
		number_pos = -1;
	    }
	    list = append(rparen, list);     
	    if (nLeftParen == nRightParen)
		done = true;
	} else if (token == SPACE) {
	    if (symbol_pos > -1) {
		list = append(symbol, list);
		symbol_pos = -1;
	    } else if (number_pos > -1) {
		list = append(number, list);
		number_pos = -1;
	    }
	    if ((previous_token != LPAREN) && (previous_token != SPACE) && (expr[i + 2] != RPAREN))
		list = append(space, list);
	} else {
	    printf("Unknown error, token: %c\n", token);
	    done = true;
	}
	i++;
	previous_token = token;
	token = expr[i];
    }

    return list;
}

// let's start simple
typedef union type {
    int int_t;
} type;

typedef struct sexp {
    type* car;
    struct sexp *cdr;
} sexp;

// sexp* read(cell* list)
// {
// }

int main(void)
{
    const char *expression = "(* ( abc  1    toto  )   4  )";

    cell *list = NULL;
    cell *cur = NULL;

    sexp *s = NULL;
  
    list = parse(expression);

    cur = list;
    while (cur != NULL) {
	printf("%s", cur->value);
	cur = cur->next;
    }
    printf("\n");

    // s = read(list);
  
    // result = eval(sexp);            

    return EXIT_SUCCESS;
}
