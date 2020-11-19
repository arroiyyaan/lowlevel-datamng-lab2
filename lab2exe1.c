/*===THIS CODE IS MEANT TO COMPLY EXERCISE 1 OF LAB 2*/
//for more convenient assessment --> https://github.com/arroiyyaan/LLDM-Lab2

#define MAN_PID 300
#define MAX_PID 5000
#define COUNT_TO 1000
#define MAX_CORES 100

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

pid_t getpid(void);
long long i = 0;

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

        if (i >= COUNT_TO) {

            return NULL;
        }
        ++i;
        printf("i = %lld\n", i);
    }
}
int main()
{
  int arr[] = {};

  int n=5;

  for (i = 0; i < MAX_CORES; ++i) {
      start_counting(i);
      delay(100);
      printf("arr[%d] = %d \n",i, arr[i]);

      int allocate_map(void);

      int allocate_pid(void);

      void release_pid(int pid);

      pid_t myPID = getpid();

      printf("my PID = %lu \n", myPID);

      pid_check(myPID);

  }


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
