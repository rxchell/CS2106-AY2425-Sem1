// ptr is a pointer to an integer
int *ptr;   // int *ptr is a pointer to a variable of type “int”
int x = 5;
ptr = &x;   // ptr now points to 5.

// To access the integer variable “x” using ptr
y = *ptr;   // y = x

// a pointer to a pointer to an integer
int **pptr;  // a pointer to a variable of type “int *”: 
pptr = &ptr;

// To access ptr from pptr by using *pptr:
int *ptr2 = *pptr;   // ptr2 = ptr

// C passes parameters by value; 
// Thus, the only way to allow a function to change a pointer is to pass a pointer to the pointer.

// eg writing a function to allocate memory to store data
void alloc_mem(int **ptr) {
  *ptr = malloc(sizeof(int));
}
...
int *p;
// Allocate memory and assign to p
alloc_mem(&p);


// free memory pointed to by a pointer, and set that pointer to NULL:
void free_mem(int **ptr) {
  if(*ptr != NULL) {
    free(*ptr);
    *ptr = NULL; 
  }
}




