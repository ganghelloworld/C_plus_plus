#include <iostream>
#include <cstdio>
using namespace std;
#define FIELD(a) char* a##_string
class Test
{
public:
	Test(){};
	Test(Test& t){}
	void func(int a, int i = 0);
};

void Test::func(int a, int i)
{
	cout << "In Test i = " << i << endl;
}

int func(int a, int i = 0);
Test create_test()
{
	Test t;
	return t;
}
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
	Test rvalue;
	rvalue = create_test();
	Test te(rvalue);
	cout << "====================" << endl;
	int test[10] = {0, 1, 2};
	int (&ref_test)[10] = test;
	cout << ref_test[4] << endl;
	int* const& p_test = test;
	cout << *(p_test + 3) << endl;
}
int func(int a, int i)
{
	printf("Hello i = %d\n", i);
}
