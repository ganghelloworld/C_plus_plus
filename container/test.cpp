#include "stash.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Stash int_stash(sizeof(int));
	for(int i = 0; i < 100; i++)
	{
		int_stash.add(&i);
	}
	for(int j = 0; j < int_stash.count(); j++)
	{
		cout << "ini_stash.fetch(" << j << ") = " << *(int *)int_stash.fetch(j) << endl;
	}
	const int bufsize = 80;
	Stash string_stash(sizeof(char) * bufsize, 100);
	ifstream in("test.cpp");
	
	string line;
	while(getline(in, line))
	{
		string_stash.add((char *)line.c_str());
	}
	int k = 0;
	char *cp;
	while((cp = (char *)string_stash.fetch(k++)) != 0)
	{
		cout << cp << endl;
	}
}
