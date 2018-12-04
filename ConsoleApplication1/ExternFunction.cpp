#include "pch.h"

// global variable used in main
int i_global = 7; 

// It can be used in main without using a header(.h)
// Only needs its prototype at the top of the main.cpp

// Because headers(.h) are used as preprocessor directives
// that embeded its content in code. If (.h) only have
// prototypes (functions or classes) it will be the same
// as writing all the prototypes at the point of the 'include'
void printHelloWorld() {
	std::cout << "Hello word!" << std::endl;
}