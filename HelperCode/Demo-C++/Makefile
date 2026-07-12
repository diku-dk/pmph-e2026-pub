CXX = g++ -O3

HELPERS = helper.h
SRC_OUR = main.cu
KER_OUR = ker-helpers.cu.h ker-addition.cu.h ker-classic-mul.cu.h ker-fft-mul.cu.h
EXE_OUR = big-num-our

default: run

templates: helper.h templates.cpp
	$(CXX) templates.cpp -o templates
	
stencil2D: helper.h stencil.cpp
	$(CXX) stencil.cpp -o stencil2D

run: templates stencil2D
	./templates 100000
	./stencil2D 10000 10000

clean:
	rm -f templates stencil2D
