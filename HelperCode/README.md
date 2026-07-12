# Helpful Hints about Cuda, Futhark and C++ Programming

## Lab 1: Simple CUDA Programming

A very simple helper CUDA code is provided in [Lab-1-Cuda](Lab-1-Cuda). In the first lab, your task is to extend the code to execute correctly on GPUs a program that multiplies each element of an array of arbitrary size with two.

Another thing that is good to hear early (and often) is that, in the context of GPUs' global memory, spatial locality means, under a slight simplification, that consecutive threads access consecutive memory locations. This is refer to as "coalesced access". More exactly: consecutive threads in a warp access a set of contiguous locations in global memory during a load instruction (executed in lockstep/SIMD). A funny exercise is to change the access pattern of the write so that consecutive threads access memory with a stride greater than 16. How much is the performance affected?

## Lab 2: List Homomorphisms in Futhark

A demonstration of how to integrate benchmarking and validation directly in Futhark programs is shown in [Lect-1-LH/mssp.fut](Lect-1-LH/mssp.fut). Go in the corresponding folder and try

```bash
$ futhark test --backend=cuda mssp.fut
```

Have the tests succeeded?

Next you can try to also benchmark, by:

```bash
$ futhark bench --backend=cuda mssp.fut
```

If runtimes are displayed then the program also validated (in the cases for which a reference result was specified). Now try reading the code in `mssp.fut`, in particular w.r.t. the multiple ways of specifying the input and reference datasets directly specified inside that file (in case you did not already look).   Understanding the automatic testing procedure will probably help you in benchmarking and validating the implementation of the Longest-Satisfying-Segment Problem (LSSP), which is the subject of the first weekly. 

Please also read the comment below function `mk_input` in `mssp.fut`. This dynamic casting of type sizes will be very useful later on, when we flatten parallelism in Futhark.

## Lab3: C++ programming demonstrating templates and operator overloading

File [Demo-C++/templates.cpp](Demo-C++/templates.cpp) demonstrates the use of C++ templates aimed at building a result vector by applying a generic binary operator to corresponding elements from two input vectors. This is tested for addition and multiplication operators. Moreover, we demonstrate generic-type towers by also abstracting out as a type parameter the underlying element type. For example, we can define addition over vectors of floats, but also over vector of complex numbers. Of course, the latter requires defining a `Complex` class that is itself parameterized over the underlying numeric type, and which overloads the `+` and `*` operators.

File [Demo-C++/stencil.cpp](Demo-C++/stencil.cpp) shows a straightforward implementation of a 2D stencil of radius one. Function `stencil2DFlat` implements the stencil by flattening the indexing, because in C++ and CUDA it is not possible to declare multi-dimensional arrays when their shape is not statically known. Function `stencil2DNice` demonstrates how nicer expression can be achieved by using a wrapper class `Array2D` which overloads the `[]` operator, thus allowing multidimensional indexing of form `[i][j]`. Importantly, this does not diminish performance because the `gcc/nvcc` compiler can inline and optimize away the intermediate structures. Similarly as before, templates can be used to abstract out the element type. 
