OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Polynomials: $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o Polynomials

main.o: main.cpp LinkedPolynomial.h Node.h
	$(CC) -c main.cpp

clean: main.o Polynomials
	rm main.o Polynomials