CC=gcc
CFLAGS=-ansi -pedantic -Wall
TARGET=get_n_primes

$(TARGET).out: $(TARGET).c primes.o
	$(CC) primes.o $(TARGET).c -o $(TARGET).out -lm $(CFLAGS)

primes.o: primes.h primes.c
	$(CC) -c primes.c