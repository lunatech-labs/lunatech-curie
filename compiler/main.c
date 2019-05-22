#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"


sexp* new_char_sexp(const char* sval)
{
    char* value = malloc(sizeof(char) * SYMBOL_LENGTH);
    sexp* s = malloc(sizeof(sexp));
    s->type = CHAR;
    s->car.sval = strcpy(value, sval);
    s->cdr = NULL;
    return s;
}

sexp* new_int_sexp(int ival)
{
    sexp* s = malloc(sizeof(sexp));
    s->type = INT;
    s->car.ival = ival;
    s->cdr = NULL;
    return s;
}

sexp* new_sexp_sexp(sexp* seval)
{
    sexp* s = malloc(sizeof(sexp));
    s->type = SEXP;
    s->car.seval = seval;
    s->cdr = NULL;
    return s;
}

int plus_int(int n, int m)
{
    return n + m;
}

double plus_double(double x, double y)
{
    return x + y;
}

bool is_lparen(const char* expr)
{
    return *expr == LPAREN;
}

bool is_rparen(const char* expr)
{
    return *expr == RPAREN;
}

bool is_symbol(const char* expr)
{
    if (!isalpha(expr[0]))
	return false;

    char token;
    int i = 1;
    while ((token = expr[i++]) != '\0') {
	if (!isalnum(token))
	    return false;
    }
    return true;
}

bool is_int(const char* expr)
{
    char* stopped = NULL;
    strtol(expr, &stopped, 10);
    return *stopped == '\0';
}

bool is_double(const char* expr)
{
    char* stopped = NULL;
    strtod(expr, &stopped);
    return *stopped == '\0';
}

int main(void)
{
    // (+ 1 2)
    sexp* one = new_int_sexp(1);
    sexp* two = new_int_sexp(2);
    sexp* s = malloc(sizeof(sexp));
    s->type = IOP;
    s->car.ifun = plus_int;
    s->cdr = one;
    s->cdr->cdr = two;
    int expected = (*plus_int)(1, 2);
    int evaluated = (*s->car.ifun)(s->cdr->car.ival, s->cdr->cdr->car.ival);
    printf("expected: %d, evaluated: %d\n", expected, evaluated);
    return EXIT_SUCCESS;
}
