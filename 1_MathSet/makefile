EXE = TestSet
OBJS = TestSet.o
SOURCE = TestSet.cpp
CC = g++
DEBUG = -g -pedantic
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(EXE): $(OBJS) 
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

$(OBJS):
	$(CC) -c $(SOURCE)

clean: $(OBJS) $(EXE)
	rm $(OBJS) $(EXE)