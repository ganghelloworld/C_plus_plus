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
		void print(){cout << "Pointer()" << endl;}
		void next();
		int read();
		void top();
		void end();
		void previous();
		void set(int i);
	};
};
void Holder::Pointer::top()
{
	p = &(h->a[0]);
}
void Holder::Pointer::end()
{
	p = &(h->a[sz-1]);
}
void Holder::Pointer::previous()
{
	if(p > &(h->a[0])) p--;
}
void Holder::Pointer::next()
{
	if(p < &(h->a[sz-1])) p++;
}
int Holder::Pointer::read()
{
	return *p;
}
void Holder::Pointer::set(int i)
{
	*p = i;
}
int main()
{
	Holder h;
	Holder::Pointer hp(&h), hp2(&h);
	Holder::Pointer hpt(0);
	hpt.print();
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
