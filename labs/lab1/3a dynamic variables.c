// Bring in the malloc and free function prototypes
#include <stdlib.h>

// Allocate memory to store an int
z = (int *) malloc(sizeof(int))

// The sizeof(.) function returns the number of bytes of the type specified as its argument. 
// So sizeof(int) returns the number of bytes in an int.

// The malloc(.) function takes one argument; the number of bytes to allocate. 
// The malloc(.) function then returns a pointer to the memory that was allocated.
  
// The malloc(.) function’s return type is “void *”. W
// While it seems strange to have a pointer to void, this is used in C to indicate a “generic” data type.

// We want to assign the return pointer to a variable “z” of type int *. 
// Thus we need to type-cast the “void *” return type of malloc(.) to int *.


// When we are done using the memory, we call free. 
free(z); 
// Frees memory pointed to by z.
