CC=gcc
CFLAGS=-ansi -pedantic -std=c11 -pipe -march=native -Wall -I. -L. -time
DEBUGFLAGS=-g -O0
RELEASEFLAGS=-Os

default: all

all: clean rot13 

release: clean
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -c -fpic librot13.c
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -shared -o librot13.so librot13.o
	$(CC) $(CFLAGS) $(RELEASEFLAGS) -lrot13 rot13.c -o rot13
	strip -sxX rot13 librot13.so
	ls -l ./librot13.so ./rot13

debug: clean
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c -fpic librot13.c
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -shared -o librot13.so librot13.o
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -lrot13 rot13.c -o rot13
	ls -l ./librot13.so ./rot13

librot13:
	$(CC) $(CFLAGS) -c -fpic librot13.c
	$(CC) $(CFLAGS) -shared -o librot13.so librot13.o

rot13: librot13
	$(CC) $(CFLAGS) -lrot13 rot13.c -o rot13

example: librot13
	$(CC) $(CFLAGS) -lrot13 example.c -o example


tests:
	./rot13 this is a normal test 123 
	./rot13 -5 this is a rot5 test 123 
	./rot13 THIS IS AN UPPER CASE TEST
	./rot13 this is a special character test \!\@\#\$\%\^\&\*\(\)\-\=\_\+ test

clean:
	rm a.out rot13 *.o *.so 2> /dev/null || true
