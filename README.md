# Rot13

This is a simple rot13 implentation written in C.  It includes both a command line verison and library.

Supports [ROT13](http://en.wikipedia.org/wiki/ROT13) with [optionally] [ROT5](http://en.wikipedia.org/wiki/ROT13#Variants) extension or [ROT47](http://en.wikipedia.org/wiki/ROT13#Variants).


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

### Motivation
I'm trying to [re]learn, C, Make and git!  Feedback, constructive criticism, and pull requests are appreciated!

# Building

Makefile is include, just run `make`.  No external deps.  Tested with "gcc version 4.7.2 (Debian 4.7.2-5)"

# Usage:

Usage: ./rot13 [options] [text || stdin]

Options:
         -, --              Reads from STDIN.
        -v, --verbose       Verbose output.
        -5, --rot5          Use ROT13 with ROT5 for numbers.
       -13, --rot13         Use ROT13 (default).
       -47, --rot47         Use ROT47.
        -h, --help          Prints help menu.


















