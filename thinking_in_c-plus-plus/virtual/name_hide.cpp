#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	virtual int f() const
	{
		cout << "Base::f()" << endl;
		return 1;
	}
	virtual int f(string) const 
	{
		cout << "Base::f(string)" << endl;
		return 1;
	}

	virtual void g()
	{
		cout << "Base::g()" << endl;
	}
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived1 : public Base
{
public:
	void g() const //redefine
	{
		cout << "Derived1::g()" << endl;
	}
	~Derived1()
	{
		cout << "~Derived1()" << endl;
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
	int f() const //change return value
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
	Base * d = new Derived1;
	delete d;
	/*
	Derived4 d;
	d.g();
	d.f(1);
	*/
	//d.f(s);
}
