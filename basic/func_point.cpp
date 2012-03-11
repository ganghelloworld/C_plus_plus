#include <iostream>
#include <cstdio>

using namespace std;

#define FP(x) \
	void x(){ cout << #x << endl;}

FP(a); FP(b); FP(c); FP(d); FP(e); FP(f); FP(g);

typedef void (*fp)();

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		cout << "Usage : ./" << argv[0] << " char(a~g)" << endl;
		return -1;
	}

	fp func_arr[7] = {a, b, c, d, e, f, g};

	int index = static_cast<int>(argv[1][0] - 'a');

	(*func_arr[index])();

	return 0;
}
