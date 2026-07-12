#ifndef HELPER
#define HELPER

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h> 

template<class T>
void validate(const uint64_t N, T* ref, T* res) {
  for(uint64_t i = 0; i < N; i++) {
    if(ref[i] != res[i]) {
      printf("INVALID result at index %ld: refernce is %f result is %f\n", i, ref[i], res[i]);
      exit(0);
    }
  }
  printf("VALID!\n");
}

template<class T>
void initArray(const uint64_t N, T* inp_arr) {
    for(uint64_t i=0; i<N; i++) {
        inp_arr[i] = 2.0 * ( ((T)rand()) / RAND_MAX );
    }
}

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    unsigned int resolution=1000000;
    long int diff = (t2->tv_usec + resolution * t2->tv_sec) - (t1->tv_usec + resolution * t1->tv_sec);
    result->tv_sec = diff / resolution;
    result->tv_usec = diff % resolution;
    return (diff<0);
}

#endif // HELPER
