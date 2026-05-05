Simpletron VM

A simple Virtual Machine (VM) implementation written in C. This project simulates the Simpletron, a computer that executes programs written in SML (Simpletron Machine Language).
📌 About the Project

This was developed as a learning exercise to understand how a CPU's fetch-decode-execute cycle works. The Simpletron handles its own memory (100 words), an accumulator register, and a specialized set of operation codes for input/output, arithmetic, and flow control.
🛠️ Features

    Memory Management: Simulates 100 memory locations.

    Instruction Set: Includes Read/Write, Load/Store, Arithmetic (Add, Sub, Mult, Div), and Branching (Jump, Jump if Zero, Jump if Negative).

    Error Handling: Detects division by zero, accumulator overflow, and invalid operation codes.

    Memory Dump: A visual debug tool that displays the state of all registers and memory locations upon termination or error.

🚀 Getting Started
Prerequisites

You only need a C compiler (like gcc or clang).
Compilation

Clone the repository and run the following command in your terminal:
Bash

gcc main.c simpletron.c -o simpletron

Running

Execute the compiled program:
Bash

./simpletron

📖 SML Instruction Set

The Simpletron uses a four-digit integer format +OOAA, where OO is the Operation Code and AA is the Memory Address.
Code	Operation	Description
10	READ	Reads a word from the terminal into memory.
11	WRITE	Prints a word from memory to the terminal.
20	LOAD	Loads a value from memory into the Accumulator.
21	STORE	Stores the Accumulator value into memory.
30	ADD	Adds a memory value to the Accumulator.
43	HALT	Terminates the program.
📂 Project Structure

    simpletron.h: Header file containing constants and function prototypes.

    simpletron.c: Implementation of the VM logic (boot, load, execution, and dump).

    main.c: The entry point of the application.
