/* Your implementation of flex_reduce goes here */
/* clear: a pointer to function to clear_res
 * op: pointer to operate on the elements of the queue
 *
 * void (*clear)(double *)
 * A function pointer to a function that clears or initializes the accumulator (_res). 
 * Takes a pointer to a double and sets it to an initial value 
 * (e.g., 0.0 for sum, 1.0 for product).
 *
 * double (*op)(double, double)
 * A function pointer to the operation function that specifies how elements of the queue should be   combined with the accumulator.
 * For example, this could be a sum or product operation.
*/

double flex_reduce(void (*clear)(double*), double (*op)(double, double)) {
  // set initial index to the last
  int ndx = _rear;

  // clear function pointer to set the initial value of _res
  clear(&_res);

  // traverse from the rear to the front index 
  while(ndx != _front) {

    // combine current element with accumulator _res 
    // using operation function specified by the op pointer
    _res = op(_queue[ndx], _res);
    
    // ensures that once ndx reaches the end of the array (MAX_Q_SIZE - 1), 
    // it wraps around to the beginning (0) rather than going out of bounds.
    ndx = (ndx + 1) % MAX_Q_SIZE;
  }
  return _res;
}

// prototype in queue.h
double flex_reduce(void (*clear)(double *), double (*op)(double, double));

// compile: gcc testr.c queue.c -o testr
// run testr: ./testr
