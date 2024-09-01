char proto_example(int x, float y, double z) {
    // ... Body of function ...
}

// prototype:
char proto_example(int, float, double);

// do not need to specify the names of the parameters, only the types.
// The prototype definition ends with a semicolon.

// Function prototypes should always be defined before the function is called at any point in your C program. 
// Eg Since in lab1.c we will be calling enq and deq inside main, we need to create their prototypes before main.
// Define the prototypes in queue.h, which will be in #include queue.h into lab1.c
