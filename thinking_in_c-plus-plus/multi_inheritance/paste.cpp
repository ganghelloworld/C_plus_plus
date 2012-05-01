#include "vendor.h"
#include <iostream>

using namespace std;

class MyBase
{
public:
	virtual void v() const = 0;
	virtual void f() const = 0;
	virtual void g() const = 0;
	virtual ~MyBase(){ cout << "MyBase::~MyBase()" << endl; };
};
void C(const MyBase& mb)
{
	mb.v();
	mb.f();
}
class MyPaste: public MyBase, public Vendor
{
public:
	void v() const
	{ 
		cout << "Paste::v()" << endl; 
		Vendor::v();
	}
	void f() const
	{
		cout << "Paste::f()" << endl;
		Vendor::f();
	}
	void g() const
	{
		cout << "Paste::g()" << endl;
	}
	~MyPaste()
	{
		cout << "Paste::~Paste()" << endl;
	}
};
int main()
{
	MyPaste& plp = *new MyPaste;
	MyBase& mp = plp;
	mp.f();
	mp.v();
	mp.g();
	cout << "=====================" << endl;
	A(plp);
	C(plp);
	delete &mp;
}
