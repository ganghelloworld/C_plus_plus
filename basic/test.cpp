#include <iostream>
#include "basic.h"
using namespace std;

class Test
{
	const int a;
	int b;
public:
	Test() : a(10)
	{
	};
	Test(int aa):a(aa)
	{
		b = 10;
	};
	void func();
	~Test()
	{
		cout << "Test::~Test()" << endl;
	};
};
void Test::func()
{
	cout << "a = " << a << endl;
};

void test()
{
	cout << "hello world" << endl;
};
int main()
{
	Test a;
	a.func();
	Test b;
	b.func();
	test();
	cout << "=====================" << endl;
	cout << Basic::a << Basic::s << endl;
}
