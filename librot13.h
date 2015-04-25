#ifndef ROT13_H
#define ROT13_H

#define ROT13_VERSION_STRING  "0.7"

static const int ASCII_UPPERCASE_A='A';
static const int ASCII_UPPERCASE_Z='Z';

static const int ASCII_LOWERCASE_A='a';
static const int ASCII_LOWERCASE_Z='z';

static const int ASCII_NUMBER_0='0';
static const int ASCII_NUMBER_9='9';

// start and end of our printable space
static const int ASCII_PRINTABLE_START=33;
static const int ASCII_PRINTABLE_END=126;


typedef enum {ROT5, ROT13, ROT13_ROT5, ROT47 } rot_type;

extern bool rot (rot_type rotType, char *input, char *output);
int rollover(int min, int max, int step, int input);

#endif
