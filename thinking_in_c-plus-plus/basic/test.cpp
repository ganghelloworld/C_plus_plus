#include <iostream>
#include <string>
using namespace std;

int main()
{
	string con = "hello";
	char ch = 'w';
	int in = 65;
	string tag = string("") + ch;
	cout << "tag size = " << tag.size() <<  endl <<
		"tag =|" << tag << "|" << endl;
}
