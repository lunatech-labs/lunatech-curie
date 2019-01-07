#include <stdio.h>
#include <stdbool.h>

int main(void)
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
      nLeftParen += 1;
      printf("%c", token);
      i += 1;
      break;
    case ')':
      nRightParen += 1;
      printf("%c", token);
      i += 1;
      if (nLeftParen == nRightParen)
        done = true;
      break;
    default:
      printf("%c", token);
      i += 1;
      break;
    }
  }
}
