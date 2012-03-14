#include <iostream>

using namespace std;
class X{
public:
	X();
};

X::X(){};

void f(int i)
{
	if(i < 100)
	{
		goto jump1;
	}
jump1:
	switch(i)
	{
		case 1:
			break;
		case 2:
			break;
	}
	X x1;
	X x2;
	X x3;
}

int main()
{
	f(9);
	f(11);
}
