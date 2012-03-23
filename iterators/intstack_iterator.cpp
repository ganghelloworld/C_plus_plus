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
	class iterator
	{
		IntStack& is;
		int index;
	public:
		iterator(IntStack& i, bool b = true) : is(i)
		{
			if(b) index = 0;
			else index =  is.top - 1;
		}

		int operator++()
		{
			if(index >= 0 && index < is.top)
			{
				return is.s[++index];
			}
			return -1;
		}
		int operator--()
		{
			if(index > 0 && index < is.top)
			{
				return is.s[--index];
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
		int operator--(int)
		{
			if(index >= 0 && index <= is.top)
			{
				return is.s[index--];
			}
			return -1;
		}
		friend ostream& operator<<(ostream& os, iterator& it)
		{
			return os << it.is.pos(it.index);
		}
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, false); }
};


int main()
{
	IntStack is;
	for(int i = 0; i < 10; i++)
	{
		is.push(i);	
	}
	int num = is.count();

	IntStack::iterator isbt = is.begin();
	IntStack::iterator iset = is.end();
	for(int i = 0; i < num; i++)
	{
		cout << "num " << i << " = " << isbt << "\t" << iset << endl;
		++isbt;
		--iset;
	}
}
