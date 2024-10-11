#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

#define NUM_PROCESSES 5

int main() {
    int i, j, pid;

    // Create shared memory for the array of semaphores
    int shm_id = shmget(IPC_PRIVATE, NUM_PROCESSES * sizeof(sem_t), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory to get the semaphores array
    sem_t *sems = (sem_t *)shmat(shm_id, NULL, 0);
    if (sems == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize the semaphores in the shared memory
    for (i = 0; i < NUM_PROCESSES; i++) {
        sem_init(&sems[i], 1, 0); // Initialize each semaphore with 0 and share between processes
    }

    // Unlock the first semaphore so that the first child can start
    sem_post(&sems[0]);

    for (i = 0; i < NUM_PROCESSES; i++) {
        if ((pid = fork()) == 0) {
            break;  // Only child process continues here
        }
    }

    if (pid == 0) {  // Child process code
        // Wait for the semaphore corresponding to this process to be unlocked
        sem_wait(&sems[i]);

        printf("I am child %d\n", i);
        for (j = i * 10; j < i * 10 + 10; j++) {
            printf("%d ", j);
            fflush(stdout);
            usleep(250000);  // Sleep for 250ms
        }
        printf("\n\n");

        // Unlock the semaphore for the next process (i+1)
        if (i + 1 < NUM_PROCESSES) {
            sem_post(&sems[i + 1]);
        }

        // Detach from the shared memory
        shmdt(sems);
    } else {  // Parent process code
        for (i = 0; i < NUM_PROCESSES; i++) {
            wait(NULL);  // Wait for all child processes to finish
        }

        // Detach and destroy the shared memory and semaphores
        shmdt(sems);
        shmctl(shm_id, IPC_RMID, NULL);  // Remove shared memory

        for (i = 0; i < NUM_PROCESSES; i++) {
            sem_destroy(&sems[i]);  // Destroy each semaphore
        }
    }

    return 0;
}


// Explanation
// 1. create and attach the shared memory region for the array of semaphores.
// 2. initialize each of the semaphores in the array with a for loop and using sem_init(&sems[il, 1, 0); This initializes each sems[il with value O and the '1' indicates that we are sharing the semaphore between processes.
// 3. Increment and unlock the first index's semaphore so that the first child can start execution. sem_post(&sems[0]);
// 4. Before starting the child process, we do a sem_wait for the semaphore at index i, waiting for the semaphore signal for our own index before starting execution.
// 5. After the current child process has finished execution, we do a sem_post for the semaphore at index i+1, to release and "unlock" the semaphore for the next child process so that it can start execution.
// 6. At the end of the program we detach and destroy the shared memory region for both the shared memory counter variable and the array of semaphores.
