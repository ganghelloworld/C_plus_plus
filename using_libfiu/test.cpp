#include <iostream>
#include <cstdio>
#include <cassert>
#include <fiu.h>
#include <fiu-control.h>

using namespace std;

size_t free_space()
{
	cout << "in free_space, return 0" << endl;
	fiu_return_on("no_free_space", 0);
	cout << "in free_space, return 100" << endl;
	return 100;
}
bool file_fits()
{
	if(free_space() < 10)
	{
		cout << "in file_fits, return false" << endl;
		return false;
	}
	cout << "in file_fits, return true" << endl;
	return true;
}
int main()
{
	//fiu_init(0);
	//fiu_enable("no_free_space", 1, NULL, 0);
	cout << "start" << endl;
	assert(file_fits() == true);
	cout << "through" << endl;
}
