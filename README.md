# Rot13 Overview

This is a simple rot13 implentation written in C.  It includes both a command line verison and library.

Supports [ROT13](http://en.wikipedia.org/wiki/ROT13) with [optionally] [ROT5](http://en.wikipedia.org/wiki/ROT13#Variants) extension or [ROT47](http://en.wikipedia.org/wiki/ROT13#Variants).

# Motivation
I'm trying to [re]learn, C, Make and git!  Feedback, constructive criticism, and pull requests are appreciated!

# Features
- [x] Reads from command line
- [x] Reads from STDIN (for interactive console or piping)
- [x] No Heap allocation
- [x] Compiles cleanly with C99 or C11 compiler without warnings

### Supports
- [x] ROT13
- [x] ROT5 (for numbers)
- [x] ROT47 (extended ROT13)

### Platforms:
- [x] Linux
- [x] Mac
- [ ] Windows


# Using the program:

make # to build program

export LD_LIBRARY_PATH=. # path where librot13.so lives

./rot13 --help # to get usage

# Using the library:

see example.c (see Makefile for compling directions)














