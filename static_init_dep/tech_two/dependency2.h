#ifndef DEPENDENCY2_H
#define DEPENDENCY2_H

#include <iostream>
#include "dependency1.h"

class Dependency2
{
	Dependency1 d1;
public:
	Dependency2(const Dependency1& dep1) : d1(dep1)
	{
		std::cout << "Dependency2 contruction" << std::endl;
		print();
	}
	void print() const
	{
		d1.print();
	}
};

#endif //DEPENDENCY2_H
