#include <stdio.h>

// Operation Codes

#define READ 10 // Reads a word from the terminal to a specific location in memory.

#define WRITE 11 // Writes a word from a specific location in memory to the terminal.

#define LOAD 20 // Loads a word from a specific location in memory to the accumulator.

#define STORE 21 // Stores a word from the accumulator to a specific location in memory.

#define ADD 30 // Adds a word from a specific location in memory to the word in the accumulator (leaves the result in the accumulator).

#define SUB 31 // Subtracts a word from a specific location in memory from the word in the accumulator (leaves the result in the accumulator).

#define DIV 32 // Divide a word from a specific location in memory by the word in the accumulator (leave the result in the accumulator).

#define MULT 33 // Multiplies a word from a specific location in memory by the word in the accumulator (leaves the result in the accumulator).

#define BRANCH 40 // It diverts to a specific location in memory.

#define BRANCHNEG 41 // It diverts to a specific location in memory if the accumulator is negative.

#define BRANCHZERO 42 // It jumps to a specific location in memory if the accumulator is zero.

#define HALT 43 // Halt, that is, the program has finished its task.


// Functions Prototypes


void boot(); // boot Simpletron

int load_program(int[], int); // write and load program to memory

int run_program(int[], int*, int*, int*, int*, int*); // start the execution of program loaded

void dump_program(const int[], const int, const int, const int, const int); // memory and registers dump
