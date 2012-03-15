#
CPP = g++
O = -o
C = -c
OBJ = test.o stash.o

all : test stack_test

test: $(OBJ)
	$(CPP) $(O) test $(OBJ)

stack_test: stack_test.cpp stack.h
	$(CPP) $(O) stack_test stack_test.cpp

test.o: test.cpp stash.h
	$(CPP) $(C) $<

stash.o: stash.cpp stash.h
	$(CPP) $(C) $<

clean:
	rm -rf test stack_test
	rm -rf *.o
