#include "initializer.h"
using namespace std;
int two()
{
	cout << "In file Tow" << endl;
	return 0;
}
static int a = two();
int main()
{
	cout << "inside main()" << endl;
	cout << "leaving main()" << endl;
}
