#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

template<class T, int size = 100>
class Stack
{
	T s[size];
	int top;
public:
	Stack() : top(0){}
	int push(T& t);
	T& pop();
	int num(){ return top; }
};
template<class T, int size>
int Stack<T, size>::push(T& t)
{
	s[top++] = t;
	return top - 1;
}
template<class T, int size>
T& Stack<T, size>::pop()
{
	if(top < 0 || top >= size)
	{
		cout << "out of the bound" << endl;
		exit(1);
	}
	return s[--top];
}

int main()
{
	Stack<string, 100> s;
	string line;
	ifstream in("stack_template.cpp");

	while(getline(in, line))
	{
		s.push(line);
	}
	int num = s.num();
	while(num--) cout << s.pop() << endl;
	return 0;
}
