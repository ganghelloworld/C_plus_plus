#ifndef INITIALIZER_H
#define INITIALIZER_H
#include <iostream>
extern int x;
extern int y;

class Initializer
{
	static int init_count;
public:
	Initializer()
	{
		std::cout << "Initializer()" << std::endl;
		if(init_count++ == 0)
		{
			std::cout << "performing initializer" << std::endl;
			x = 100;
			y = 200;
		}
	}
	~Initializer()
	{
		std::cout << "~initializer()" << std::endl;
		if(--init_count == 0)
		{
			std::cout << "performing cleanup" << std::endl;
		}
	}
};
static Initializer init;
#endif //INITIALIZER_H
