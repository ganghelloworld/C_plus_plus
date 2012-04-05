#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s("Hello World");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(100);
	s.append(" Hello gang");
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	return 0;
}
