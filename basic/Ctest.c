#include <stdio.h>

void f(int i)
{
	if(i < 100)
	{
		goto jump1;
	}
	int a;
jump1:
	switch(i)
	{
		case 1:
			a = 2;
			printf("in case 1; a = %d\n", a);
			int b;
			break;
		case 2:
			printf("in case 2\n");
			b = 3;
			break;
		default:
			printf("in case default\n");
			break;
	}
}
int func();
int main()
{
	int i = 0;
	int a = 3;
	int *p = &a;
	void *q = p;
	int *s = q;
	f(1);
	f(11);
	for(i = 0; i < 10; i++)
		func(10, 20);
}

int func(int a, int b)
{
	printf("Hello %d\t%d\n", a, b);
}
