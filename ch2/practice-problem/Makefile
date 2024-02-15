# Makefile
CC = gcc
CFLAGS = -Wall -g

all: reverse mtk4g mxic

reverse: inplace-swap.o reverse.o
	$(CC) $(CFLAGS) -o reverse inplace-swap.o reverse.o

inplace-swap.o: inplace-swap.c inplace-swap.h
	$(CC) $(CFLAGS) -c inplace-swap.c

reverse.o: reverse.c inplace-swap.h
	$(CC) $(CFLAGS) -c reverse.c

mtk4g: interview_mtk_4g_2016.c
	$(CC) $(CFLAGS) -o mtk4g interview_mtk_4g_2016.c

mxic: interview_mxic_fw_2021.c
	$(CC) $(CFLAGS) -o mxic interview_mxic_fw_2021.c

.PHONY: clean
clean:
	rm -f *.o reverse