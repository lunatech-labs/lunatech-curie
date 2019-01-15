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

typedef enum symbol_type {CHAR, INT, DOUBLE, SEXP, IOP, DOP} symbol_type;

typedef int (*iop)(int, int);
typedef double (*dop)(double, double);

struct sexp;

typedef union value {
    char* sval;
    int ival;
    double dval;
    struct sexp* seval;
    iop ifun;
    dop dfun;
} value;

typedef struct sexp {
    symbol_type type;
    value car;
    struct sexp *cdr;
} sexp;

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
    s->car.seval = s;
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

sexp* new_plus_int_sexp()
{
    sexp* s = malloc(sizeof(sexp));
    s->type = IOP;
    s->car.ifun = &plus_int;
    s->cdr = NULL;
    return s;
    
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

    return EXIT_SUCCESS;
}
