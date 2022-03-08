/* hello.c */
//
// Created by katar on 08.03.2022.
//

#include <stdio.h>
#include <stdlib.h>

void maximize(int* beg, int size) {
  for (int i = 0; i < size; ++i) {
    int counts[10];
    for (int j = 0; j < 10; ++j) {
      counts[j] = 0;
    }
    while(beg[i] > 0) {
      ++counts[beg[i] % 10];
      beg[i] /= 10;
    }
    for (int j = 9; j >= 0; --j) {
      while (counts[j] > 0) {
        beg[i] *= 10;
        beg[i] += j;
        --counts[j];
      }
    }
  }
}
int main (int argc, char** argv)
{
  int* test_arr = (int*)malloc((argc - 1) * sizeof(int));
  for(int i = 1; i < argc; ++i) {
    test_arr[i - 1] = atoi(argv[i]);
  }
  maximize(test_arr, argc - 1);
  for (int i = 0; i < argc - 1; ++i) {
    printf("%i ", test_arr[i]);
  }
  
  free(test_arr);
}