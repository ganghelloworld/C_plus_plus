#include "static.h"
#include <iostream>

using namespace std;

int main()
{
	A a;
	a.set_bid(10);
	cout << "id = " << a.get_count() << endl;
	cout << "bid = " << a.get_bid() << endl;

	A b;
	cout << "id = " << b.get_count() << endl;
}
