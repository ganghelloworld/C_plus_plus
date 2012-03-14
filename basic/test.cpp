#include <iostream>
#include <cstdio>
using namespace std;

int func(int, int);
int main()
{
	func(10, 10);
	int a = 3;
	int *p = &a;
	void *q = p;
	int *s = q;
}

int func(int a, int)
{
	printf("Hello %d\n", a);
}
