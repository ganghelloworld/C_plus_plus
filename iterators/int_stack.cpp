#include <iostream>

using namespace std;

class IntStack
{
	enum { size = 100};
	int s[size];
	int top;
public:
	IntStack() : top(0) {}
	int push(int a)
	{
		s[top++] = a;
	}
	int pop()
	{
		return s[--top];
	}
	int count(){ return top; }
	int pos(int index)
	{
		return s[index];
	}
	friend class intStackIterator;
};

class intStackIterator
{
	IntStack& is;
	int index;
public:
	intStackIterator(IntStack& i) : is(i), index(0){}

	int operator++()
	{
		//cout << "index = " << index << endl;
		if(index >= 0 && index < is.top)
		{
			return is.s[++index];
		}
		return -1;
	}
	int operator++(int)
	{
		if(index >= 0 && index < is.top)
		{
			return is.s[index++];
		}
		return -1;
	}
	friend ostream& operator<<(ostream& os, intStackIterator& ist)
	{
		return os << ist.is.pos(ist.index);
	}
};

int main()
{
	IntStack is;
	for(int i = 0; i < 10; i++)
	{
		is.push(i);	
	}
	int num = is.count();

	intStackIterator ist(is);
	for(int i = 0; i < num; i++)
	{
		cout << "num " << i << " = " << ist << endl;
		++ist;
	}
}
