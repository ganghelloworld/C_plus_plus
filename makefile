#
CPP = g++
CFLAG = -c
OFLAG = -o

OBJ = test.o handle.o

test : $(OBJ)
	$(CPP) $(OFLAG) test $(OBJ)

test.o : test.cpp handle.h
	$(CPP) $(CFLAG) test.cpp

handle.o : handle.cpp
	$(CPP) $(CFLAG) handle.cpp

clean:
	rm -rf test
	rm -rf *.o
