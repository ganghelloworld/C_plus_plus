#include <iostream>
class One
{
public:
	One(){}
};

class Two
{
public:
	explicit Two(const One&){}
};

void f(Two)
{
}

int main()
{
	One one;
	f(Two(one));
}
