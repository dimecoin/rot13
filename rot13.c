#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "librot13.h"
bool verbose= false;

bool useRot5 = false;
bool useRot13 = true;
bool useRot47 = false;

void printHelp(char *name) {
	puts ("\nROT13 Version: " ROT13_VERSION_STRING "\n");

	printf("Usage: %s [options] [text || stdin]\n", name);
	printf ("\nOptions:\n");

	printf( "%10s, %-15s %s\n", "-",  "--", "Reads from STDIN.");
	printf( "%10s, %-15s %s\n", "-v",  "--verbose", "Verbose output.");
	printf( "%10s, %-15s %s\n", "-5",  "--rot5", "Use ROT13 with ROT5 for numbers.");
	printf( "%10s, %-15s %s\n", "-13",  "--rot13", "Use ROT13 (default).");
	printf( "%10s, %-15s %s\n", "-47",  "--rot47", "Use ROT47.");
	printf( "%10s, %-15s %s\n", "-h",  "--help", "Prints help menu.");
}

rot_type getRotType() {

	if (useRot5) {
		return ( ROT13_ROT5 );
	}

	if (useRot47) {
		return ( ROT47 );
	}

return (ROT13);
}
void printLine(char *input) {

	// +1 to account for null terminator
	char output[strlen(input) + 1];
	rot(getRotType(), input, output);

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
			if (strcmp(argv[i], "-13") == 0 || strcmp(argv[i], "--rot5") == 0 ) {
				useRot13 = true;
			}
			if (strcmp(argv[i], "-47") == 0 || strcmp(argv[i], "--rot5") == 0 ) {
				useRot47 = true;
			}

			if (strcmp(argv[i], "-") == 0 || strcmp(argv[i], "--") == 0) {

				char input[BUFSIZ];

				while (fgets(input, BUFSIZ, stdin)) {
					if (input[strlen(input)-1] == '\n') {
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


