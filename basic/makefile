CPP = g++
OFLAG = -o 

.SUFFIXES: .o .cpp
.cpp.o :
	$(CPP) $<

all: func_point.o

func_point: func_point.o
	$(CPP) $(OFLAG) func_point func_point.cpp
