#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "sorts.h"

#define N 100000
#define NUMBER_OF_SORTS 3
typedef enum { QUICK, MERGE, BUBBLE } sort_type;


pid_t spawn_sort_process(sort_type t);
void spawn_quick_sort_process();
void spawn_bubble_sort_process();
void spawn_merge_sort_process();

void fill_array(int* array, int size);

int array[N] = {0};

void main(int argc, char** argv)
{
  pid_t children[NUMBER_OF_SORTS] = {0};

  fill_array(array, N);

  for (int i = 0; i < NUMBER_OF_SORTS; ++i)
    children[i] = spawn_sort_process((sort_type) i);

  for (int i = 0; i < NUMBER_OF_SORTS; ++i)
    wait(NULL);
}

pid_t spawn_sort_process(sort_type t)
{
  pid_t pid = fork();

  switch (pid)
  {
  case 0:
    return pid;
    break;

  case -1:
    perror("Error in fork()");
    exit(1);
    break;
  
  default:
    switch (t)
    {
    case QUICK:  spawn_quick_sort_process();  break;
    case MERGE:  spawn_merge_sort_process();  break;
    case BUBBLE: spawn_bubble_sort_process(); break;

    default:
      break;
    }
    break;
  }
}

void fill_array(int* array, int size)
{

}

void spawn_quick_sort_process()
{

}

void spawn_merge_sort_process()
{

}

void spawn_bubble_sort_process()
{
  
}
