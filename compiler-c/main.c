#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  char token;
  bool done = false;

  char buf[10] = "(+ 1 2)";
  int i = 0;
  while (!done) {
    token = buf[i];;
    switch(token) {
    case '(':
      i += 1;
      break;
    case ')':
      done = true;
      break;
    default:
      printf("%c", token);
      i += 1;
      break;
    }
  }
}
