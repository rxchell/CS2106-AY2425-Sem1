// Function pointers are pointers to functions, useful in implementing “callbacks”

int *func(int x) {
            ...
}
// function returns a pointer to an int
// takes an int as a parameter

int (*fptr)(int x);
//  pointer to a function that returns an “int” 
// takes an int as an argument


int (*fptr)(int);
// “fptr” declared as a pointer to a function returning “int”

int *(*pfptr)();
// “pfptr” as a pointer to a function returning int *

// assign func to fptr and func2 to pfptr
fptr = func;    // NOT  fptr = &func;
pfptr = func2;  // NOT  pfptr = &func2;
// the name of a function is a pointer to the function
// just like the name of an array is a pointer to the first element of the array.


