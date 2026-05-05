#include "simpletron.h"

void boot() {

   printf("*** Welcome to Simpletron! ***\n");
   printf("*** Please type your program, one instruction ***\n");
   printf("*** (or data word) at a time. I will show ***\n");
   printf("*** the location number and a question mark (?). ***\n");
   printf("*** You will then need to type the word for that ***\n");
   printf("*** location. Type the sentinel -99999 to ***\n");
   printf("*** end your program entry. ***\n\n");

}

int load_program(int memory[], int size_memory) {

   int input = 0, count = 0;

   while (1) {
   
      printf("%+03d ? ", count);
      scanf("%d", &input);

      if (input == -99999) break;

      if (input < -9999 || input > 9999) {
      
         printf("Please enter something in the range of -9999 to +9999\n\n");
	 continue;
      
      }

      memory[count] = input;

      count += 1;

      if (count > size_memory) {
      
         printf("*** Memory excedeed. ***\n\n");

	 return -1
      
      }
   
   }

   printf("*** Program load completed. ***\n");
   printf("*** Starting program execution ***\n\n");

   return 0;

}

int run_program(int memory[], int *accumulator, int *pc, int *operationCode, int *operand, int *Register) {

   *accumulator = 0;
   *pc = 0;
   *operationCode = 0;
   *operand = 0;
   *Register = 0;

   while (1) {
   
      *Register = memory[*pc];

      *operationCode = *Register / 100;
      *operand = *Register % 100;

      switch (*operationCode) {
      
	      case 10:

		      printf("Input: ");
		      scanf("%d", &memory[*operand]);

		      break;

	      case 11:

		      printf("\nOutput: %d\n", memory[*operand]);

		      break;

	      case 20:

		      *accumulator = memory[*operand];

		      break;

	      case 21:

		      memory[*operand] = *accumulator;

		      break;

	      case 30:

		      *accumulator += memory[*operand];

		      break;

	      case 31:

		      *accumulator -= memory[*operand];

		      break;

	      case 32:

                      if (memory[*operand] == 0) {
		      
                         printf("*** Attempt to divide by zero at this memory location: %+05d ***\n\n", *operand);

		         return -1;
		      
		      }

		      *accumulator /= memory[*operand];

		      break;

	      case 33:

		      *accumulator *= memory[*operand];

		      break;

	      case 40:

		      *pc = *operand;

		      continue;

	      case 41:

		      if (*accumulator < 0) {
		      
		         *pc = *operand;
		      
		      }

		      continue;

	      case 42:

		      if (*accumulator == 0) {
		      
		         *pc = *operand;
		      
		      }

		      continue;

	      case 43:

		      return 0;

	      default:

		      printf("*** Invalid operation code at this location: %+05d ***\n\n", *pc);
		      return -1;
      
      }

      if (*accumulator < -9999 || *accumulator > 9999) {
      
         printf("*** Accumulator overflow error. ***\n\n");
	 return -1;
      
      }

      *pc += 1;

      if (*pc > size_memory) {
      
         printf("*** Program Counter overflow ***\n\n");

	 return -2;
      
      }
   
   }

}

void dump_program(const int memory[], const int accumulator, const int pc, const int instructionCode, const int operand) {

   printf("REGISTERS:\n\n");

   printf("accumulator: %+03d\nprogram_counter: %+03d\ninstruction_code: %+03d\noperand: %+03d\n\n", accumulator, pc, instructionCode, operand);

   printf("MEMORY:\n\n");

   for (int i = 0; i <= 9; i++) {
   
      printf("\t%2d", i);
   
   }

   printf("\n\n");

   for (int j = 0; j <= 9; j++) {
   
      printf("%d ", j * 10);

      for (int x = 0; x <= 9; x++) {
      
         printf("\t%+05d ", memory[(j * 10) + x]);
      
      }

      printf("\n");
   
   }

}
