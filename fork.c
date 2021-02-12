#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "sorts.h"

#define N 100000
#define NUMBER_OF_SORTS 3
typedef enum { QUICK, MERGE, BUBBLE } sort_type;

void quick_sort_process();
void bubble_sort_process();
void merge_sort_process();

void fill_array(int* array, int size);

int array[N] = {0};

void main(int argc, char** argv)
{
  pid_t children[NUMBER_OF_SORTS] = {0};

  fill_array(array, N);

  for (int i = 0; i < NUMBER_OF_SORTS; ++i)
  {
    pid_t pid = fork();

    switch (pid)
    {
    case 0:
      switch ((sort_type) i)
      {
      case QUICK:  quick_sort_process();  break;
      case MERGE:  merge_sort_process();  break;
      case BUBBLE: bubble_sort_process(); break;

      default:
        break;
      }
      break;

    case -1:
      perror("Error in fork()");
      exit(1);
      break;
    
    default:
      children[i] = pid;
      break;
    }
  }

  for (int i = 0; i < NUMBER_OF_SORTS; ++i)
    wait(NULL);
}

void fill_array(int* array, int size)
{
  srand(time(NULL));
  for (int i = 0; i < size; ++i)
    array[i] = rand() % 100;
}

void quick_sort_process()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  quick_sort(array, N);
  gettimeofday(&end, NULL);

  printf("Time for quick sort: %lu\n", (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec);
  exit(0); 
}

void merge_sort_process()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  merge_sort(array, N);
  gettimeofday(&end, NULL);

  printf("Time for merge sort: %lu\n", (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec);
  exit(0);
}

void bubble_sort_process()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  bubble_sort(array, N);
  gettimeofday(&end, NULL);

  printf("Time for bubble sort: %lu\n", (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec);
  exit(0);
}
