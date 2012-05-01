CPP = g++
C = -c
O = -o
OBJ = one.o two.o initializerDefs.o

two:$(OBJ)
	$(CPP) $(O) two $(OBJ)
two.o:two.cpp initializer.h
	$(CPP) $(C) $<
one.o:one.cpp initializer.h
	$(CPP) $(C) $<
initializerDefs.o:initializerDefs.cpp initializer.h
	$(CPP) $(C) $<

clean:
	rm -rf *.o
	rm -rf two
