CPP = g++
OFLAG = -o 

.SUFFIXES: .o .cpp
.cpp.o :
	$(CPP) $(OFLAG) $@ $<

all: func_point.o

clean:
	rm *.o
