#include <string.h>
#include <stdbool.h>


#include "librot13.h"

/**
 * helper function to roll over value once it hits max
 * min : min value allowed (starting point which will be rolled over to)
 * max : max value allowd (will roll over past this point back to min)
 * step : numer of places to move
 * input : input number
 *
 * Note:
 * 	 this assumes step will be less than (max - min)
 * 	 no error checking
 *
 */
int rollover(int min, int max, int step, int input) {

	int output = input + step;

	if (output > max) {
		output = min -1 + (output % max) ;
	}

return (output);
}

/**
 * Takes an input string, applies rot and provides an output string
 *  
 * rotType: rot_type defined in header file
 * input:  string to convert
 * output: pointer to string to return
 *
 */
void rot (rot_type rotType, char *input, char *output) {

	for (int i=0; i<strlen(input); i++) {
		int asci = (int) input[i];

		if (rotType == ROT13 || rotType == ROT13_ROT5) {

			if (asci >= ASCII_UPPERCASE_A && asci <= ASCII_UPPERCASE_Z) {
				asci = rollover(ASCII_UPPERCASE_A, ASCII_UPPERCASE_Z, 13, asci);
			}

			if (asci >= ASCII_LOWERCASE_A && asci <= ASCII_LOWERCASE_Z) {
				asci = rollover(ASCII_LOWERCASE_A, ASCII_LOWERCASE_Z, 13, asci);
			}
		}
		
		if (rotType == ROT5 || rotType == ROT13_ROT5) {
			if (asci >= ASCII_NUMBER_0 && asci <= ASCII_NUMBER_9)  {
				asci = rollover(ASCII_NUMBER_0, ASCII_NUMBER_9, 5, asci);
			}
		}

		if (rotType == ROT47) {
			if (asci >= ASCII_PRINTABLE_START && asci <= ASCII_PRINTABLE_END)  {
				asci = rollover(ASCII_PRINTABLE_START, ASCII_PRINTABLE_END, 47, asci);
			}
		}

	output[i] = (char) asci;
	}

	// terminate string
	output[strlen(input)] = '\0';	
return;
}


