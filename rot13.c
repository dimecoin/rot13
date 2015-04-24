#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "librot13.h"
bool verbose= false;
bool useRot5 = false;

void printHelp(char *name) {
	puts ("\nROT13 Version: " ROT13_VERSION_STRING "\n");

	printf("Usage: %s [options] [text || stdin]\n", name);
	printf ("\nOptions:\n");

	printf( "%10s, %-15s %s\n", "-",  "--", "Reads from STDIN.");
	printf( "%10s, %-15s %s\n", "-v",  "--verbose", "Verbose output.");
	printf( "%10s, %-15s %s\n", "-5",  "--rot5", "Use ROT5 for numbers (default is false).");
	printf( "%10s, %-15s %s\n", "-h",  "--help", "Prints help menu.");
}

void printLine(char *input) {

	char output[strlen(input)];
	rot13(input, output, useRot5);

	if (verbose) {
		printf ("In : %s\n", input);
		printf ("Out: %s\n", output);
	} else {
		printf("%s ", output);
	}

}


int main(int argc, char *argv[]) {

	// Not enough options
	if (argc < 2) {
		printHelp(argv[0]);
		exit(EXIT_FAILURE);
	}

	// Get our agruments
	for (int i=1; i<argc; i++) {

		if ( argv[i][0] == '-' ) {

			if (verbose) {
				printf("ARGV[%i] : %s\n", i, argv[i]);
		
			}	

			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
				printHelp(argv[0]);
				exit(EXIT_SUCCESS);
			}

			if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
				verbose=true;
				puts("Enabling Verbose Output\n");
			}

			if (strcmp(argv[i], "-5") == 0 || strcmp(argv[i], "--rot5") == 0 ) {
				useRot5 = true;
			}

			if (strcmp(argv[i], "-") == 0 || strcmp(argv[i], "--") == 0) {

				char input[BUFSIZ];
				while (fgets(input, sizeof(input), stdin)) {
					if (input[strlen(input)-1] == '\n') {
						//input[strlen(input)-1] = '\0';
						printLine(input);
					}
				}
				
				exit(EXIT_SUCCESS);
			}

		}
	}





	// Process our input
	for (int i=1; i<argc; i++) {

		if ( argv[i][0] == '-' ) {
			continue; 
		}

		printLine(argv[i]);
	}



printf("\n");
exit(EXIT_SUCCESS);
}
















