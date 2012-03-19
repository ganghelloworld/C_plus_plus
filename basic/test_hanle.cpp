#include "handle.h"
#include <iostream>
using namespace std;
int main()
{
	Handle h;
	h.initialize();
	cout << h.read() << endl;
	h.change(1);
	h.print();
	cout << h.read() << endl;
	h.cleanup();
}
