###vendor.h vendor.cpp paste.cpp
run it:
	*g++ -c vendor.cpp
	*g++ paste.cpp vendor.o
	*./a.out
test repairing the interface: we can not modified vendor.cpp coded by other people, but we want refactor the Vendor based vendor.h, and cant't redefine the behavior of function A and B 

###test.cpp
run it:
	*g++ test.cpp
	*./a.out
test some feature of multiple inheritance
