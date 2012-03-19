#include "initializer.h"
using namespace std;
int x;
int y;
int Initializer::init_count;
int Defs()
{
	cout << "In file Defs" << endl;
	return 0;
}
static int a = Defs();
