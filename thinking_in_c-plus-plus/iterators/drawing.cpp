#include "stash_iterator.h"
#include "shape.h"
#include <vector>
#include <iostream>

using namespace std;

class Drawing : public PStash<Shape>
{
public:
	~Drawing(){ cout << "~Drowing()" << endl; }
};

class Plan : public vector<Shape*>
{
public:
	~Plan(){ cout << "~Plan()" << endl;}
};

template<class Iter>
void draw_all(Iter start, Iter end)
{
	while(start != end)
	{
		(*start)->draw();
		start++;
	}
}
int main()
{
	Drawing d;
	d.add(new Circle());
	d.add(new Square());
	d.add(new Line());
	draw_all(d.begin(), d.end());

	Plan p;
	p.push_back(new Circle());
	p.push_back(new Square());
	p.push_back(new Line());
	draw_all(p.begin(), p.end());

	Shape* a[] = {new Circle(), new Square(), new Line()};
	draw_all(a, a + (sizeof(a) / sizeof(*a)));
	return 0;
}
