#include <iostream>

using namespace std;

class Egg
{
	static Egg e;
	int i;
	Egg(int ii) : i(ii) {}
	Egg(const Egg&);
public:
	static Egg* instance() { return &e; }
	int val() const {return i;}
};

Egg Egg::e(47);

class Test
{
	static Egg e;
	int i;
	Test(int ii) : i(ii) {}
	Test(const Test&);
public:
	static Egg* instance() { return &e; }
	int val() const {return i;}
};

//Egg Test::e(47);

int main()
{
	// ! Egg x(1); //Error
	cout << Egg::instance()->val() << endl;
	return 0;
}
