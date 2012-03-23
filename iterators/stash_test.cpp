#include "stash_iterator.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
struct Test{
	PStash<string>::iterator itb;
	PStash<string>::iterator ite;
};
*/
int main()
{
	PStash<string>  ps;
	string line;
	ifstream in("stash_test.cpp");
	while(getline(in, line))
	{
		ps.add(new string(line));
	}
	cout << "line num = " << ps.count() << endl;
	PStash<string>::iterator itb = ps.begin();
	PStash<string>::iterator ite = ps.end();
	string* s = *ite;
	/*
	while(s)
	{
		cout << *s << endl;
		s = ++itb;
	}
	*/
	itb += 3;	
	while(!(itb == ite))
	{
		cout << **itb << endl;
		itb++;
	}
	return 0;
}
