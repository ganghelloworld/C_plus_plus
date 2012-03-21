#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int f() const
	{
		cout << "Base::f()" << endl;
		return 1;
	}
	int f(string) const 
	{
		cout << "Base::f(string)" << endl;
		return 1;
	}

	void g()
	{
		cout << "Base::g()" << endl;
	}
};

class Derived1 : public Base
{
public:
	void g() const //redefine
	{
		cout << "Derived1::g()" << endl;
	}
};

class Derived2 : public Base
{
public:
	int f() const //redefine
	{
		cout << "Derived2::f()" << endl;
		return 2;
	}
};

class Derived3 : public Base
{
public:
	void f() const //change return value
	{
		cout << "Derived3::f()" << endl;
	}
};

class Derived4 : public Base
{
public:
	int f(int) const // change argument list
	{
		cout << "Derived3::f()" << endl;
		return 4;
	}
};

int main()
{
	string s("hello");
	Derived3 d;
	d.g();
	d.f();
	d.f(s);
}
