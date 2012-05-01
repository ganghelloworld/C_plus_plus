#include <iostream>
#include <string>

using namespace std;

class Dog
{
	string nm;
public:
	Dog(const string& name) : nm(name)
	{
		cout << "creating Dog : " << *this << endl;
	}
	Dog(const Dog* dp, const string& msg) : nm(dp->nm + msg)
	{
		cout << "copy Dog " << *this << " from " << *dp << endl;
	}
	~Dog()
	{
		cout << "delete Dog" << *this << endl;
	}
	void rename(const string& name)
	{
		nm = name;
		cout << "Dog rename to : " << *this << endl;
	}

	friend ostream& operator<<(ostream& os, const Dog& d)
	{
		return os << "[" << d.nm << "]";
	}
};

class DogHouse
{
	Dog* p;
	string house_name;
public:
	DogHouse(Dog* dog, const string& house) : p(dog), house_name(house){}
	DogHouse(const DogHouse& dh) : 
		p(new Dog(dh.p, " copy-constructor")), 
		house_name(dh.house_name + " copy-constructor"){}
	DogHouse& operator=(const DogHouse& dh);
	void rename_house(const string& house)
	{
		house_name = house;
	}
	Dog* get_dog(){return p;}
	~DogHouse(){delete p;}
	friend ostream& operator<<(ostream& os, const DogHouse& dh)
	{
		return os << "[" << dh.house_name << "] contains " << *dh.p;
	}
};

DogHouse& DogHouse::operator=(const DogHouse& dh)
{
	if(&dh != this)
	{
		p = new Dog(dh.p, " assigned");
		house_name = dh.house_name + " assigned";
	}
	return *this;
}

int main()
{
	DogHouse fidos(new Dog("Fido"), "Fido house");
	cout << fidos << endl;
	DogHouse fidos2(fidos); //copy-constructor
	cout << fidos2 << endl;
	fidos2.get_dog()->rename("Spot");
	fidos2.rename_house("Spot house");
	cout << fidos << endl;
	cout << fidos2 << endl;
	fidos = fidos2; //Assignment
	cout << fidos << endl;
	fidos.get_dog()->rename("Max");
	fidos2.rename_house("MaxHouse");
	cout << fidos << endl;
	cout << fidos2 << endl;
	return 0;
}
