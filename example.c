#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "librot13.h"

int main(int argc, char *argv[]) {


	char *input = "This is an example";
	// output string needs to >= input length of will seg fault!
	char output[strlen(input) + 1];

	// See header for rot_type values
	rot_type rotType = ROT13;
	bool success = rot(rotType, input, output);
	if (!success) {
		fprintf(stderr, "something bad happened with rot function!\n");
		exit (EXIT_FAILURE);
	}

	printf ("Input: %s\n", input);
	printf ("Output: %s\n", output);


printf("\n");
exit(EXIT_SUCCESS);
}


