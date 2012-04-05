#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string lowercase(string& s)
{
	char* buf = new char[s.size()];
	s.copy(buf, s.size());
	for(int i = 0; i < s.size(); i++)
	{
		buf[i] = tolower(buf[i]);
	}
	string r(buf, s.size());
	delete buf;
	return r;
}
int main()
{
	string s("a piece a text");
	string tag("$tag$");
	s.insert(2, tag + " ");
	cout << s << endl;
	int start  = s.find(tag);
	if(start == string::npos) return 0;
	cout << "start = " << start << endl;
	cout << "size = " << tag.size() << endl;
	s.replace(start, tag.size(), "hello world");
	cout << s << endl;
	replace(s.begin(), s.end(), 'l', 'L');
	cout << s << endl;

	cout << lowercase(s) << endl;

	string a("hello \t \n");
	int b = a.find_first_not_of("hl");
	int e = a.find_last_not_of(" \t\n");
	cout << "||" << string(a, b, e - b + 1) << "||" << endl;

	string::iterator  begin = s.begin();
	string::iterator  end = s.end();
	char ch;
	cout << "||" << s << "||" << endl;
	while(begin != end)
	{
		cout << *begin;
		begin++;
	}
	cout << endl;
	end--;
	while(begin < end)
	{
		cout << *begin << " <-> " << *end << endl;
		ch = *begin;
		*begin = *end;
		*end = ch;
		begin++;
		end--;
	}
	cout << "||" << s << "||" << endl;
	return 0;
}
