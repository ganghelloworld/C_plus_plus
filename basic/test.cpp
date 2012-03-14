#include <iostream>
#include <cstdio>
using namespace std;

int func(int, int);
int main()
{
	func(10, 10);
}

int func(int a, int)
{
	printf("Hello %d\n", a);
}
