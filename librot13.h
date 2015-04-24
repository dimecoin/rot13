#ifndef ROT13_H
#define ROT13_H

#define ROT13_VERSION_STRING  "0.4"

extern void rot13 (char *input, char *output, bool useRot5);
extern int rollover(int min, int max, int step, int input);

#endif
