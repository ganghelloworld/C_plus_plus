#include "template_pointer_stash.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("stash_test.cpp");
	PStash<string, 10> ps;
	string line;
	while(getline(in, line))
	{
		ps.add(new string(line));
	}
	int num = ps.count();
	for(int j = 0; j < num; j++)
	{
		cout << *ps[j] << endl;	
		delete ps.remove(j);
	}
	cout << "done" << endl;
}
