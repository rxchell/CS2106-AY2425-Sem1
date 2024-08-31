#include <stdio.h>
#include <unistd.h>

int main() {
  
  // printed 
  printf ("I am here!\n");

  // execl() System Call
  execl("/bin/ls", "ls", "-al", NULL);

  // not printed 
  printf ("Am I still here?\n");
  
  return 0;
}

// Original program code replaced with ls code region 
// Cannot return to original program 
