#include <iostream>
#include <cstring>

using namespace std;
const int sz = 20;
class Holder
{
	int a[sz];
public:
	Holder(){ memset(a, 0, sz * sizeof(int)); };
	//class Pointer;
	friend class Pointer;
};
class Pointer
{
	Holder *h;
	int *p;
public:
	Pointer(Holder* rv)
	{
		h = rv;
		p = rv->a;
	}
	void next();
	int read();
	void top();
	void end();
	void previous();
	void set(int i);
};
void Pointer::top()
{
	p = &(h->a[0]);
}
void Pointer::end()
{
	p = &(h->a[sz-1]);
}
void Pointer::previous()
{
	if(p > &(h->a[0])) p--;
}
void Pointer::next()
{
	if(p < &(h->a[sz-1])) p++;
}
int Pointer::read()
{
	return *p;
}
void Pointer::set(int i)
{
	*p = i;
}
int main()
{
	Holder h;
	Pointer hp(&h), hp2(&h);
	for(int i = 0; i < sz; i++)
	{
		hp.set(i);
		hp.next();
	}
	hp.top();
	hp2.end();
	for(int i = 0; i < sz; i++)
	{
		cout << "hp  = " << hp.read()
			 << ", hp2 = " << hp2.read() << endl;
		hp.next();
		hp2.previous();
	}
}
