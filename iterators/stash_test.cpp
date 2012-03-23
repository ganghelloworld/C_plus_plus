#include "stash_iterator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	PStash<string>  ps;
	string line;
	ifstream in("stash_test.cpp");
	while(getline(in, line))
	{
		ps.add(new string(line));
	}

	PStash<string>::iterator itb = ps.begin();
	string* s;
	while(s = itb++)
	{
		cout << *s << endl;
	}
	return 0;
}
