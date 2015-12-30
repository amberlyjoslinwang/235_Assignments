TARGET = MainBST
OBJS = MainBST.o PreconditionViolatedException.o NotFoundException.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o MainBST

MainBST.o: MainBST.cpp LinkedList.h BinarySearchTree.h
	$(CC) -c MainBST.cpp

PreconditionViolatedException.o: PreconditionViolatedException.h
	$(CC) $(CFLAGS) PreconditionViolatedException.cpp

NotFoundException.o: NotFoundException.h
	$(CC) $(CFLAGS) NotFoundException.cpp

clean: $(OBJS) $(TARGET)
	rm $(OBJS) $(TARGET)