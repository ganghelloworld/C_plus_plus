#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <new>

using namespace std;

void* operator new(size_t sz)
{
	printf("operator new: %d Bytes\n", sz);
	void *m = malloc(sz);
	if(!m) puts("out of memory");
	//throw bad_alloc();
	return m;
}

void operator delete(void *m)
{
	puts("operator delete");
	free(m);
}

class S
{
	int i[100];
public:
	S(int = 0){ cout << "S::S()" << endl; };
	~S(){ cout << "S::~S()" << endl; };
	void print() const { cout << "in S" << endl;}
};

S test(int i = 0)
{
	cout << "in function" << endl;
}
void out_of_memory()
{
	cerr << "memory exhausted" << endl;
	exit(1);
}
int main()
{
	set_new_handler(out_of_memory);
	try {
		cout << "new int and delete it!" << endl;
		int* p = new int[100];
		delete []p;
		cout << "====================" << endl;
		
		S *s = new S;
		delete s;
		cout << "====================" << endl;
		S *ss = new S();
		delete ss;
		cout << "====================" << endl;
		S *sp = new S[5];
		delete []sp;
	}catch(bad_alloc) {
		cerr << "catch memory bad alloc" << endl;
	}
}
