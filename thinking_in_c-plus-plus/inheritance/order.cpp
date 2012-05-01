#include <iostream>

using namespace std;

#define make_class(X) \
	class X \
	{ \
	public: \
		X(int){cout << #X << " constructor" << endl;} \
		~X(){cout << #X << " destructor" << endl;} \
	}; 

make_class(Base1);
make_class(Member1);
make_class(Member2);
make_class(Member3);
make_class(Member4);

class Derived1 : public Base1
{
	Member2 m2;
	Member1 m1;
public:
	Derived1() : Base1(1), m2(1), m1(1){ cout << "Derived1 constructor" << endl;}
	~Derived1(){cout << "Derived1 destructor" << endl; };
};

class Derived2 : public Derived1
{
	Member4 m4;
	Member3 m3;
public:
	Derived2() : m4(1), m3(1), Derived1(){ cout << "Derived2 constructor" << endl;}
	~Derived2(){cout << "Derived2 destructor" << endl; };
};

int main()
{
	Derived2 d2;
	return 0;
}
