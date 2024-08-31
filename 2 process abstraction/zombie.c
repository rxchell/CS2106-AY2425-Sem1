int main() {
  int result;

  result = fork();

  if (result != ) {
    printf("Parent %i goes into busy waiting!\n", getpid());
    while (1) {
      sleep(1);
    }
  }
  else {
    printf("Child %i exited!\n", getpid() );
    exit(0);
  }

  return 0;
}

// gcc zombie.c
// ./a.out
// >> Parent 77186 goes into busy waiting!    (parent goes into while loop)
// >> Child 77187 exited!                     (into zombie state)
// (zombie state killed by terminating parent or calling wait()
