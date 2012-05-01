#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

template<class T, int size = 100>
class Array
{
	T array[size];
public:
	T& operator[](int index);
};

template<class T, int size>
T& Array<T, size>::operator[](int index)
{
	if(index < 0 || index >= size)
	{
		cout << "index is not in bound" << endl;
		exit(1);
	}
	return array[index];
}

int main()
{
	int i;
	Array<int, 10> a;
	Array<string, 100> s;

	for(i = 0; i < 10; i ++)
		a[i] = i * i;

	for(i = 0; i < 10; i ++)
		cout << "a[" << i << "] = " << a[i] << endl;

	ifstream f("array.cpp");
	string line;

	i = 0;
	while(getline(f, line) != 0)
	{
		s[i++] = line;
	}
	for(int j = 0; j < i; j++)
	{
		cout << s[j] << endl;
	}
}
