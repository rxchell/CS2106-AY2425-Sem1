# include <stdio.h>

int main(void) {
  int* p = NULL;
  *p = 100;

  printf("Never printed\n");
  return 0;
}

// gcc exception.c
// ./a.out
// >> 670ii segmentation fault   ./a.out
// print statement is never printed
