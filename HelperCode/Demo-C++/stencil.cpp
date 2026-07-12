#include "helper.h"

/**
 * input:  logical array of shape (N+2) x (M+2)
 * result: logical array of shape N x M
 * We implement a 2D stencil of distance +- 1 in each dimension,
 *   but we shrink the dimension of the result in order to avoid branches.
 * What we would like to write is:
 *     result[i,j] = ( input[i,  j] + input[i,  j+1] + input[i,  j+2] +
 *                     input[i+1,j] + input[i+1,j+1] + input[i+1,j+2] +
 *                     input[i+2,j] + input[i+2,j+1] + input[i+2,j+2]
 *                   ) / 9;
 *  but we need to flatten the indices because CUDA/C++ do not support
 *  declaration of multidimensional arrays whose sizes are not statically known.  
 */
template<class T>
void stencil2DFlat( const uint64_t M
                  , const uint64_t N
                  , T* input
                  , T* result
                  )
{
    for(uint64_t i = 0; i < M; i++) {
      for(uint64_t j = 0; j < N; j++) {
          result[ i*N + j ] = (
              input[  i * (N+2)  + j ] + input[  i * (N+2)  + j+1 ] + input[  i * (N+2)  + j+2 ] +
              input[ (i+1)*(N+2) + j ] + input[ (i+1)*(N+2) + j+1 ] + input[ (i+1)*(N+2) + j+2 ] +
              input[ (i+2)*(N+2) + j ] + input[ (i+2)*(N+2) + j+1 ] + input[ (i+2)*(N+2) + j+2 ]
            ) / 9; 
      }
    }
}

/**
 * Array2D uses [] overloading to allow nicer expression
 *   of the stencil based on 2D-array indexing.
 * `array2D[i]` will create a Delayed objects that has all
 *   the neccessary information to serve the second indexing.
 *   Moreover, this come at no overhead because the gcc compiler
 *   can inline and optimize away the intermediate structures. 
 */
template<class T>
class Array2D {
  private:
    T* mem;
    uint64_t M;
    uint64_t N;
    
    class Delayed {
      private:
        T* mem;
        uint64_t N;
        uint64_t i;
        
      public:
        inline Delayed(const uint64_t n, T* buff, const uint64_t ind)
            { N = n; mem = buff; i = ind; }
        inline T& operator[](const uint64_t j)
            { return mem[ i*N + j ];    }
    };
  public:
    inline Array2D(const uint64_t m, const uint64_t n, T* buff)
        { M = m; N = n; mem = buff; }

    inline Delayed operator[](const uint64_t i)
        { return Delayed(N, mem, i); }
};

/**
 * input:  logical array of shape (N+2) x (M+2)
 * result: logical array of shape N x M
 * We Array2D to write the stencil in the desired/nicer way  
 */
template<class T>
void stencil2DNice( const uint64_t M
                  , const uint64_t N
                  , T* mem_input
                  , T* mem_result
                  )
{
    Array2D<T> input(M+2, N+2, mem_input), result(M, N, mem_result);
    
    for(uint64_t i = 0; i < M; i++) {
      for(uint64_t j = 0; j < N; j++) {
         result[i][j] = ( input[i][j]   + input[i][j+1]   + input[i][j+2] +
                          input[i+1][j] + input[i+1][j+1] + input[i+1][j+2] +
                          input[i+2][j] + input[i+2][j+1] + input[i+2][j+2]
                        ) / 9;
      }
    }
}

int main (int argc, char * argv[]) {
    if (argc != 3) {
        printf("Usage: %s <M> <N>\n", argv[0]);
        exit(1);
    }
    // read the vector length
    const uint64_t M = atoi(argv[1]);
    const uint64_t N = atoi(argv[2]);
    
    // allocate memory
    double* mem_input = (double*) malloc( (M+2)*(N+2) * sizeof(double) );
    double* mem_res1  = (double*) malloc( (M*N) * sizeof(double));
    double* mem_res2  = (double*) malloc( (M*N) * sizeof(double));
    
    // randomly initializing the input buffer
    initArray<double>( (N+2)*(M+2), mem_input);

    unsigned long int elapsed;
    struct timeval t_start, t_end, t_diff;

    {
      stencil2DFlat<double>( M, N, mem_input, mem_res1 ); // one round warmup
      
      gettimeofday(&t_start, NULL); 

      stencil2DFlat<double>( M, N, mem_input, mem_res1 );

      gettimeofday(&t_end, NULL);
      timeval_subtract(&t_diff, &t_end, &t_start);
      elapsed = t_diff.tv_sec*1e6+t_diff.tv_usec;
      printf("Running Flat stencil of shape (%lu x %lu) using double as element type took: %lu microsec\n", M, N, elapsed);
    }
    
    {
      stencil2DNice<double>( M, N, mem_input, mem_res2 );

      gettimeofday(&t_start, NULL); 

      stencil2DNice<double>( M, N, mem_input, mem_res2 );

      gettimeofday(&t_end, NULL);
      timeval_subtract(&t_diff, &t_end, &t_start);
      elapsed = t_diff.tv_sec*1e6+t_diff.tv_usec;

      printf("Running Nice stencil of shape (%lu x %lu) using double as element type took: %lu microsec\n", M, N, elapsed);
    }
    
    validate<double>(N*M, mem_res1, mem_res2);    
    
    { // free memory
      free(mem_input);
      free(mem_res1);
      free(mem_res2);
    }
}
