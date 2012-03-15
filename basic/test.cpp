#include <iostream>
#include <cstdio>
using namespace std;
#define FIELD(a) char* a##_string
class Test
{
public:
	void func(int a, int i = 0);
};

void Test::func(int a, int i)
{
	cout << "In Test i = " << i << endl;
}

int func(int a, int i = 0);

int main()
{
	char a[] = "Fenggang\n";
	FIELD(one);
	one_string =  a;
	cout << one_string << endl;
	func(10, 1);
	func(10);
	Test t;
	t.func(10);
	t.func(12, 2);
}
int func(int a, int i)
{
	printf("Hello i = %d\n", i);
}
