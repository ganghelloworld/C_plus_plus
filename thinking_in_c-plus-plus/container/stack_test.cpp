#include "string_stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream in("stash_test.cpp");
	StringStack textlines;
	string line;
	while(getline(in, line))
	{
		textlines.push(new string(line));
	}
	string *s;
	while((s = textlines.pop()) != 0)
	{
		cout << *s << endl;
		delete s;
	}
	return 0;
}
