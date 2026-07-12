#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "helper.h"
#include <assert.h>

/**
 * Complex Number over some base numeric type T
 * Requires: + and * operators are defined on T.
 */
template<class T>
class Complex {
  public:
    T real;
    T imag;
    inline Complex () { }
    inline Complex (T t1, T t2) { this->real = t1; this->imag = t2; }
    
    inline Complex<T> operator+(const Complex& c1) {
      Complex<T> res;
      res.real = this->real + c1.real;
      res.imag = this->imag + c1.imag;
      return res; 
    }

    inline Complex<T> operator*(const Complex& c1) {
      Complex<T> res;
      res.real = this->real * c1.real - this->imag * c1.imag;
      res.imag = this->real * c1.imag + this->imag * c1.real; 
      return res;
    }
};

/**
 * Generic Addition as binary operator that can be
 *  instantiated over various numeric types, such as
 *  int32_t, int64_t, float, double, but also over
 *  user-defined types that have + and * operators
 *  defined on them, such as Complex<T>.
 */
template<class T>
class Add {
  public:
    using BType = T;
    static inline T apply(T t1, T t2) { return (t1 + t2); }
};

/**
 * Generic Multiplication as binary operator, similar to Add.
 */
template<class T>
class Mul {
  public:
    using BType = T;
    static inline T apply(T t1, T t2) { return (t1 *  t2); }
};

/**
 * Applying a generic binary operator to two input vectors
 */
template<class Bop> void
applyBinOp2Vect( const uint64_t N
               , typename Bop::BType* vector1
               , typename Bop::BType* vector2
               , typename Bop::BType* result
               )
{
  for(uint64_t i = 0; i < N; i++) {
    result[i] = Bop::apply(vector1[i], vector2[i]);
  }
}

int main (int argc, char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <vector-length>\n", argv[0]);
        exit(1);
    }
    // read the vector length
    const uint64_t N = atoi(argv[1]); 
    
    // allocate memory
    void* mem1  = malloc(N * sizeof(double));
    void* mem2  = malloc(N * sizeof(double));
    void* memr1 = malloc(N * sizeof(double));
    void* memr2 = malloc(N * sizeof(double));
    
    // randomly initializing the input array 
    initArray<float>(2*N, (float*)mem1);
    initArray<float>(2*N, (float*)mem2);

    {
      printf("Running Addition on vectors of length %lu using float as element type\n", 2*N);
      float *vect1 = (float*) mem1, *vect2 = (float*) mem2, *res = (float*)memr1;
      applyBinOp2Vect< Add<float> >( 2*N, vect1, vect2, res );
    }
    
    {
      printf("Running Addition on vectors of length %lu using Complex<float> as element type\n", N);
      using C = Complex<float>;
      C *vect1 = (C*) mem1, *vect2 = (C*) mem2, *res = (C*)memr2;
      applyBinOp2Vect< Add<C> >( N, vect1, vect2, res );
    }
    
    validate<float>(2*N, (float*)memr1, (float*)memr2);

    {
      printf("Running Multiplication on vectors of length %lu using double as element type\n", N);
      double *vect1 = (double*) mem1, *vect2 = (double*) mem2, *res = (double*)memr1;
      applyBinOp2Vect< Mul<double> >( N, vect1, vect2, res );
    }
    
    {
      printf("Running Multiplication on vectors of length %lu using Complex<float> as element type\n", N);
      using C = Complex<float>;
      C *vect1 = (C*) mem1, *vect2 = (C*) mem2, *res = (C*)memr2;
      applyBinOp2Vect< Mul<C> >( N, vect1, vect2, res );
    }
    
    printf("No Validation is performed from Multiplication due to Cosmin being lazy!\n");
    
    
    { // free memory
      free(mem1);
      free(mem2);
      free(memr1);
      free(memr2);
    }
}
