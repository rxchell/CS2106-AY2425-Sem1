#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <semaphore.h>

int _nproc;     // Number of processes that need to reach the barrier
int _shmid, _shmid2;
sem_t *_sems;   // Semaphore array (contains barrier and mutex)
sem_t *_barrier, *_mutex;  // Individual semaphores for barrier and mutex
int *_count;    // Shared counter to track how many processes have reached the barrier

void init_barrier(int numproc) {
  _nproc = numproc;

  _shmid = shmget(IPC_PRIVATE, 2 * sizeof(sem_t), IPC_CREAT | 0600);
  _shmid2 = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);

  _sems = (sem_t*) shmat(_shmid, NULL, 0);
  _count = (int*) shmat(_shmid2, NULL, 0);
  _count[0] = 0;

  _barrier = &_sems[0];
  _mutex = &_sems[1];

  sem_init(_barrier, 1, 0);
  sem_init(_mutex, 1, 1);
}

void reach_barrier() {
  sem_wait(_mutex);
  _count[0]++;
  sem_post(_mutex);;

  if(_count[0] >= _nproc) {
    // Release the barrier
    sem_post(_barrier);
  }
  else
  {
    // Wait at the barrier
    sem_wait(_barrier);

    // Once we wake, we wake our neighbor
    sem_post(_barrier);
  }
}

void destroy_barrier(int my_pid) {
    if(my_pid != 0) {
        // Destroy the semaphores and detach
        // and free any shared memory. Notice
        // that we explicity check that it is
        // the parent doing it
        sem_destroy(_barrier);
        sem_destroy(_mutex);

        // Detach shared memory
        shmdt(_sems);
        shmdt(_count);

        // Remove shared memory segments
        shmctl(_shmid, IPC_RMID, NULL);
        shmctl(_shmid2, IPC_RMID, NULL);
    }
}
