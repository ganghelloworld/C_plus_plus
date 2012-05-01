#include <iostream>

using namespace std;

class Pet
{
public:
	int id;
	Pet() : id(1) {cout << "Pet id = " << id << endl;}
	char eat() const { cout << "eat()" << endl; return 'a'; };
	int speak() const { cout << "speak()" << endl; return 1; };
	float sleep() const { cout << "sleep()" << endl; return 3.0; };
	double sleep(int) const { cout << "sleep(int)" << endl; return 4.0; };
	void print_id() const { cout << "in func id = " << id << endl;}
};

class Goldfish : Pet
{
public:
	using Pet::eat;
	using Pet::sleep;
	using Pet::print_id;
	using Pet::id;
	void print() const 
	{
		speak();
		cout << "in Goldfish id = " << id << endl;
	}
};

int main()
{
	Goldfish gf;
	gf.eat();
	gf.sleep();	
	gf.sleep(1);
	gf.print();
	cout << "in main id " << gf.id << endl;
}
