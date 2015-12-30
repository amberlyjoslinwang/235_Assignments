TARGET = TEST
OBJS = test.o InfixToPostfixCalculator.o PreconditionViolatedException.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o Test

test.o: Test.cpp InfixToPostfixCalculator.h LinkedStack.h Node.h PreconditionViolatedException.h
	$(CC) -c Test.cpp

InfixToPostfixCalculator.o: InfixToPostfixCalculator.h
	$(CC) $(CFLAGS) InfixToPostfixCalculator.cpp

PreconditionViolatedException.o: PreconditionViolatedException.h
	$(CC) $(CFLAGS) PreconditionViolatedException.cpp

clean: $(OBJS) $(TARGET)
	rm $(OBJS) $(TARGET)