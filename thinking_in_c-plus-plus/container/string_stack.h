#ifndef STRING_STACK_H
#define STRING_STACK_H

#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class StringStack : public Stack
{
public:
	void push(string* s)
	{
		Stack::push(s);
	}
	string* peek() const
	{
		return (string *)Stack::peek();
	}
	string* pop()
	{
		return (string *)Stack::pop();
	}
	~StringStack()
	{
		string *top = pop();
		while(top)
		{
			delete top;
			top = pop();
		}
	}
};

#endif //STRING_STACK_H
