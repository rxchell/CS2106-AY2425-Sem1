#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define NUM_PROCESSES 5

int main() {
    int i, j, pid;

    // Create shared memory for 'turn' variable
    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to process
    int *turn = (int *)shmat(shm_id, NULL, 0);
    *turn = 0;  // Initialize 'turn' to 0

    for (i = 0; i < NUM_PROCESSES; i++) {
        if ((pid = fork()) == 0) {
            break;  // Only child process continues here
        }
    }

    if (pid == 0) {  // Child process code
        while (*turn != i) {
            // Wait for our turn (busy waiting)
        }

        printf("I am child %d\n", i);
        for (j = i * 10; j < i * 10 + 10; j++) {
            printf("%d ", j);
            fflush(stdout);
            usleep(250000);  // Sleep for 250ms
        }
        printf("\n\n");

        // Update the turn to pass control to the next process
        *turn = *turn + 1;

        // Detach shared memory
        shmdt(turn);
    } else {  // Parent process code
        for (i = 0; i < NUM_PROCESSES; i++) {
            wait(NULL);  // Wait for all child processes to finish
        }

        // Detach and remove shared memory
        shmdt(turn);
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}


// output:

// I am child 0
// 0 1 2 3 4 5 6 7 8 9 

// I am child 1
// 10 11 12 13 14 15 16 17 18 19 

// I am child 2
// 20 21 22 23 24 25 26 27 28 29 

// I am child 3
// 30 31 32 33 34 35 36 37 38 39 

// I am child 4
// 40 41 42 43 44 45 46 47 48 49 
