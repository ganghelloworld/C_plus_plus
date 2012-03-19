#
CPP = g++
OBJ = test.o two.o one.o
test : $(OBJ)
	$(CPP) -o test $(OBJ)

.SUFFIXES: .cpp .o
.cpp.o:
	$(CPP) -c $<

clean:
	rm -rf *.o
	rm test
