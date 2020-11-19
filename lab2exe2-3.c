/*===THIS CODE IS MEANT TO COMPLY EXERCISE 2 AND 3 OF LAB 2*/
//for more convenient assessment --> https://github.com/arroiyyaan/LLDM-Lab2

#define MAN_PID 300
#define MAX_PID 5000
#define COUNT_TO 1000
#define MAX_CORES 100

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long i = 0;
pid_t getpid(void);

int pid_check(pid_t myPID)
{
  //pid_t myPID = getpid();

  while(waitpid(-1, 1) > 0)
  {
    return 0;
  }

  if (0 == kill(myPID, 0))

  {
    return 1;
  }
}

void *start_counting(void *arg) {
    for (;;) {
        // lock revealing
        pthread_mutex_lock(&mutex);
        if (i >= COUNT_TO) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        ++i;

        // lock release
        pthread_mutex_unlock(&mutex);

        printf("i = %lld\n", i);
    }
}

int main()
{
  int arr[] = {};
  int n=5;
  int i = 0;

  for(int i=0; i<n; i++)
  {
    start_counting(MAX_CORES);
  }
  int allocate_map(void);

  int allocate_pid(void);

  void release_pid(int pid);

  pid_t myPID = getpid();

  printf("my PID = %lu \n", myPID);

  pid_check(myPID);

  //SYNCHRONIZATION
  //thread creation
  pthread_t *thread_group = malloc(sizeof(pthread_t) * MAX_CORES);

  // ignite all threads
  for (i = 0; i < MAX_CORES; ++i) {
      pthread_create(&thread_group[i], NULL, start_counting, NULL);
  }

  // threads await
  for (i = 0; i < MAX_CORES; ++i) {
      pthread_join(thread_group[i], NULL);
  }

  return 1;
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
