###vendor.h vendor.cpp paste.cpp
run it:
	1. g++ -c vendor.cpp
	2. g++ paste.cpp vendor.o
	3. ./a.out
test repairing the interface: we can not modified vendor.cpp coded by other people, but we want refactor the Vendor based vendor.h, and cant't redefine the behavior of function A and B 

###test.cpp
run it:
	1. g++ test.cpp
	2. ./a.out
test some feature of multiple inheritance
