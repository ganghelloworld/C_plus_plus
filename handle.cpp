#include "handle.h"
#include <iostream>

using namespace std;

struct Handle::Cheshire
{
	int i;

	void hello();
};

void Handle::Cheshire::hello()
{
	cout << "hello" << endl;
}

void Handle::initialize()
{	
	read_num = 0;
	smile = new Cheshire;
	smile->i = 0;
}
void Handle::cleanup()
{
	delete smile;
}
int Handle::read()
{
	read_num++;
	return smile->i;
}
void Handle::change(int a)
{
	smile->i = a;
}
void Handle::print()
{
	smile->hello();
	cout << "print" << endl;
}

