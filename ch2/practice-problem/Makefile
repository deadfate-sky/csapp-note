# Makefile
CC = gcc
CFLAGS = -Wall -g

all: reverse

reverse: inplace-swap.o reverse.o
	$(CC) $(CFLAGS) -o reverse inplace-swap.o reverse.o

inplace-swap.o: inplace-swap.c inplace-swap.h
	$(CC) $(CFLAGS) -c inplace-swap.c

reverse.o: reverse.c inplace-swap.h
	$(CC) $(CFLAGS) -c reverse.c

clean:
	rm -f *.o reverse