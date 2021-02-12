#include "sorts.h"
#include <stdlib.h>

int comp(int* i, int* j);
void merge(int* array, int l, int m, int r);

void quick_sort(int* array, int size)
{
  qsort(array, sizeof(int), size, (int(*) (const void *, const void *)) comp);
}

void merge_sort(int* array, int size)
{
  
}

void bubble_sort(int* array, int size)
{
  for (int pass = 1; pass < size; ++pass)
  {
    for (int i = 0; i < size - 1; ++i) {
      if (array[i] > array[i + i]) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
}

int comp(int* i, int* j)
{
  return *i - *j;
}
