#include "initializer.h"
using namespace std;
int one()
{
	cout << "In file One" << endl;
	return 0;
}
static int a = one();
