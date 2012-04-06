#include <iostream>
#include <vector>

using namespace std;

#define WRITE(arg) \
	cout << #arg << " = " << arg << endl

class Parent
{
public:
	virtual void hello() const = 0;
};
class Base
{
	char c[0x10];
public:
	Base(int i = 0){}
	virtual string vf() const { return "Base"; };
	virtual ~Base(){}
};
class Derived: public Base
{
public:
	string vf(){ return "Derived";}
};
class Derived1: virtual public Base
{
public:
	Derived1():Base(1){}
	string vf() const { return "D1"; }
};

class Derived2: virtual public Base
{
public:
	Derived2():Base(1){}
	string vf() const { return "D2"; }
};

class Mi: public Derived1, public Derived2, public Parent
{
public:
	Mi(int i):Base(1){}
	void hello() const{};
	Mi():Base(1){}
	string vf() const { return "Mi"; }
};

class X: public Mi
{
public:
	X():Base(1){}
	string vf() const { return "X"; }
};

int main()
{
	vector<Base*> vb;
	vb.push_back(new Derived1);
	vb.push_back(new Derived2);
	vb.push_back(new Mi);
	vb.push_back(new X);
	for(int i = 0; i < vb.size(); i++)
	{
		cout << vb[i]->vf() << endl;
	}
	Base b;
	WRITE(sizeof b);
	Derived d;
	WRITE(sizeof d);
	Derived1 d1;
	WRITE(sizeof d1);
	Derived2 d2;
	WRITE(sizeof d2);
	Mi m;
	WRITE(sizeof m);
	X x;
	WRITE(sizeof x);
}
