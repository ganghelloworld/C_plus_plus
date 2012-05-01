#include <iostream>
#include <string>

using namespace std;

class Dog
{
	string nm;
	int ref_count;
	Dog(const string& name) : nm(name), ref_count(1)
	{
		cout << "creating Dog : " << *this << endl;
	}
	Dog& operator=(const Dog& rv);
public:
	static Dog* make(const string& name)
	{
		return new Dog(name);
	}
	Dog(const Dog& d) : nm(d.nm + " copy"), ref_count(1)
	{
		cout << "Dog copy-constructor: " << *this << endl;
	}
	~Dog()
	{
		cout << "delete Dog" << *this << endl;
	}
	void attach()
	{
		++ref_count;
		cout << "Attached Dog: " << *this << "ref_count = " << ref_count << endl;
	}
	void detach()
	{
		if(ref_count != 0)
		{
			cout << "Detaching Dog : " << *this << endl;
			if(--ref_count == 0) delete this;
		}
	}
	Dog* unalias()
	{
		cout << "Unaliasing Dog: " << *this << endl;
		if(ref_count == 1) return this;
		--ref_count;
		return new Dog(*this);
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
	DogHouse(Dog* dog, const string& house) : p(dog), house_name(house)
	{
		cout << "Created DogHouse : " << *this << endl;
	}
	DogHouse(const DogHouse& dh) : 
		p(dh.p), 
		house_name(dh.house_name)
	{
		p->attach();
		cout << "DogHouse copy-constructor: " << *this << endl;
	}
	DogHouse& operator=(const DogHouse& dh);
	void rename_house(const string& house)
	{
		house_name = house;
	}
	Dog* get_dog(){return p;}
	~DogHouse()
	{
		cout << "DogHouse destructor: " << *this << endl;
		p->detach();
	}
	void unalias()
	{
		p = p->unalias();
	}
	void rename_dog(const string& new_name)
	{
		unalias();
		p->rename(new_name);
	}
	friend ostream& operator<<(ostream& os, const DogHouse& dh)
	{
		return os << "[" << dh.house_name << "] contains " << *dh.p;
	}
};

DogHouse& DogHouse::operator=(const DogHouse& dh)
{
	if(&dh != this)
	{
		house_name = dh.house_name + " assigned";
		p->detach();
		p = dh.p;
		p->attach();
	}
	cout << "DogHouse operator= : " << *this << endl;
	return *this;
}

int main()
{
	DogHouse fidos(Dog::make("Fido"), "Fido house");
	DogHouse spot(Dog::make("Spot"), "Spot house");
	cout << "=========================copy-constructor" << endl;
	DogHouse bobs(fidos);
	cout << "=========================assigned" << endl;
	spot = fidos;
	cout << "=========================slef assigned" << endl;
	bobs = bobs;
	cout << "=========================bobs rename" << endl;
	bobs.rename_dog("Bob");
	cout << bobs << endl;
	cout << fidos << endl;
	cout << spot << endl;
	return 0;
}
