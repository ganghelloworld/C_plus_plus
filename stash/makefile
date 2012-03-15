#
CPP = g++
O = -o
C = -c
OBJ = test.o stash.o

test: $(OBJ)
	$(CPP) $(O) test $(OBJ)

test.o: test.cpp stash.h
	$(CPP) $(C) $<

stash.o: stash.cpp stash.h
	$(CPP) $(C) $<

clean:
	rm -rf test
	rm -rf *.o
