#ifndef DEPENDENCY1_H
#define DEPENDENCY1_H

#include <iostream>

class Dependency1
{
	bool init;
public:
	Dependency1() : init(true)
	{
		std::cout << "Dependency1 contruction" << std::endl;
	}
	void print() const
	{
		std::cout << "Dependency1 init " << init << std::endl;
	}
};

#endif //DEPENDENCY1_H
