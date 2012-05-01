#
CPP = g++
C = -c
O = -o
all : stack_test

stack_test : stack_test.o
	$(CPP) $(O) stack_test stack_test.cpp
stack_test.o : stack_test.cpp stack.h string_stack.h
	$(CPP) $(C) stack_test.cpp
clean:
	rm -rf stack_test
	rm -rf *.o
