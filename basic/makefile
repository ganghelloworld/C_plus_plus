CPP = g++
CC = gcc
O = -o 
C = -c
all : func_point test Ctest Nojump

func_point : func_point.cpp
	$(CPP) $(O) func_point $<
test : test.cpp
	$(CPP) $(O) test $<

Ctest : Ctest.c
	$(CC) $(O) Ctest $<

Nojump : Nojump.cpp
	$(CPP) $(O) Nojump $<
clean:
	rm func_point test Ctest Nojump
