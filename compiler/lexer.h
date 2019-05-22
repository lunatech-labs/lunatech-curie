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

sexp* new_char_sexp(const char* sval);
