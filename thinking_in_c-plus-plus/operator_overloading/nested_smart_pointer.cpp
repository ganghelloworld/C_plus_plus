#include <iostream>
#include <vector>

using namespace std;

class Obj
{
	static int i, j;
public:
	void f() const {cout << i++ << endl;}
	void g() const {cout << j++ << endl;}
};
int Obj::i = 0;
int Obj::j = 0;

class ObjContainer
{
	vector<Obj*> a;
public:
	void add(Obj* o) {a.push_back(o);}
	class SmartPointer
	{
		ObjContainer& oc;
		int index;
	public:
		SmartPointer(ObjContainer& objc) : oc(objc) {index = 0;}

		bool operator++()
		{
			if(index >= oc.a.size()) return false;
			if(oc.a[++index] == 0) return false;
			return true;
		}
		bool operator++(int)
		{
			return operator++();
		}
		Obj* operator->() const
		{
			if(index >= oc.a.size() || index < 0) return 0;
			return oc.a[index];
		}
	};
	SmartPointer begin()
	{
		return SmartPointer(*this);
	}
};


int main()
{
	const int sz = 10;
	Obj o[sz];
	ObjContainer oc;
	for(int i = 0; i < sz; i++)
	{
		oc.add(&o[i]);
	}
	ObjContainer::SmartPointer sp = oc.begin();
	do{
		sp->f();
		sp->g();
	}while(sp++);
	return 0;
}
