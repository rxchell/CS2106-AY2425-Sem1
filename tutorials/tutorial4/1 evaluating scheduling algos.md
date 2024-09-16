### Conditions where FCFS (FIFO) resulting in the shortest possible average response time
If the jobs happen to arrive in the ready queue with the shortest completion
times first (or, as a special case, if all jobs have the same completion time).

### Conditions where Round-Robin (RR) scheduling behave identically to FIFO
If the job lengths are no longer than the length of the time slice.

### Conditions where RR scheduling perform poorly compared to FIFO
If the job lengths are all the same, and much greater than the time slice length

### Does reducing the time slice for Round-Robin scheduling help or hurt its performance relative to FIFO?
- If turnaround time is the priority - reducing time slice increases the % time the OS is doing
work as a fraction of CPU time. Hence we get less efficient usage of CPU time.
- Opposite if initial reponse time is prioritised

### Which scheduling algorithm gives a higher priority to I/O-bound processes for the CPU?
- Multi-Level Feedback Queue (MLFQ)
- SJF




