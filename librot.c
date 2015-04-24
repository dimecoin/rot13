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
 * input:  string to convert
 * output: pointer to string to return
 *
 * This is the standard rot13 encoding.  
 * Upper case stays upper case and lower case stays lower case.
 * both shifted 13 letters
 * no affect on special characters or numbers
 *
 */
void rot (rot_type rotType, char *input, char *output) {

	// This makes sure output is in a good state... 
	// if we dont' do this and they pass in array then it can get garbled for small values
	// for example "a" is outputed as "nhgchg"
	// memory corruption?  strcpy fixes it.
	strcpy(output, input);

	for (int i=0; i<strlen(input); i++) {
		int asci = (int) input[i];


		if (rotType == ROT13 || rotType == ROT13_ROT5) {
			// 65 = A, 90=Z
			if (asci >= 65 && asci <= 90) {
				asci = rollover(65, 90, 13, asci);
			}

			// 97=a, 122 = z	
			if (asci >= 97 && asci <= 122) {
				asci = rollover(97, 122, 13, asci);
			}
		}
		
		if (rotType == ROT5 || rotType == ROT13_ROT5) {
			// 48=0, 57=9
			if (asci >= 48 && asci <= 57)  {
				asci = rollover(48, 57, 5, asci);
			}
		}

		if (rotType == ROT47) {
			// 48=0, 57=9
			if (asci >= 33 && asci <= 126)  {
				asci = rollover(33, 126, 47, asci);
			}
		}

	output[i] = (char) asci;
	}
	

return;
}


