#ifndef ROT13_H
#define ROT13_H

#define ROT13_VERSION_STRING  "0.4"

typedef enum {ROT5, ROT13, ROT13_ROT5, ROT47 } rot_type;

extern void rot (rot_type rotType, char *input, char *output);
int rollover(int min, int max, int step, int input);

#endif
