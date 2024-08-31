#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
  int i;

  for(i = 0; i < argc; i++) { 
    printf("Arg %i: %s\n", i, argv[i]);
  }

  exit(0);
  return 123;
}

// gcc exit.c
// ./a.out
// >> Arg 0: ./a.out

// echo $?
// >> 0
