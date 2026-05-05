#include "simpletron.h"

int main(void) {

   int memory[100] = {0};

   int accumulator, pc, operationCode, operand, Register;

   int result, entry;

   boot();

   entry = load_program(memory, sizeof(memory) / sizeof(memory[0]));

   if (entry == 0) {

      result = run_program(memory, &accumulator, &pc, &operationCode, &operand, &Register);

      switch (result) {
   
         case 0:

	         printf("*** Simpletron execution terminated. ***\n\n");
	         break;

         case -1:

	         printf("*** Simpletron execution terminated abnormally. ***\n\n");
	         printf("*** Please check the memory map to find the error. ***\n\n");
   
                 dump_program(memory, accumulator, pc ,operationCode, operand);

	         break;

      }

   } else {
   
      return -1;
   
   }

   return 0;

}
