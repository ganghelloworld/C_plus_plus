#include <iostream>

using namespace std;

class Widget
{
	enum { num = 4};
	void f(int) const{cout << "Widget::f()" << endl;}
	void g(int) const{cout << "Widget::g()" << endl;}
	void m(int) const{cout << "Widget::m()" << endl;}
	void n(int) const{cout << "Widget::n()" << endl;}
	void (Widget::*fp[num])(int) const;
public:
	int a,b,c;
	Widget()
	{
		a = b = c = 1;
		fp[0] = &Widget::f;
		fp[1] = &Widget::g;
		fp[2] = &Widget::m;
		fp[3] = &Widget::n;
	}
	void select(int i, int para) const
	{
		if(i < 0 || i >= num) return;
		(this->*fp[i])(para);
	}
	void print() const
	{
		cout << "a = " << a << "\t"
			 << "b = " << b << "\t"
			 << "c = " << c << endl;
	}
	int count(){return num;};
};
int main()
{
	Widget w;
	for(int i = 0; i < w.count(); i++)
	{
		w.select(i, 47);
	}
	int Widget::*mem = &Widget::a;
	w.print();
	w.*mem = 2;
	w.print();
	mem = &Widget::b;
	w.*mem = 3;
	w.print();
	mem = &Widget::c;
	w.*mem = 4;
	w.print();
	Widget *p = new Widget();
	p->print();
	p->*mem = 5;
	p->print();
}
