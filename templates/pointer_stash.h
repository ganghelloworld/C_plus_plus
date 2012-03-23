#ifndef TEMPLATE_POINTER_STASH
#define TEMPLATE_POINTER_STASH

#include <iostream>
using namespace std;

template<class T, int inc = 10>
class PStash
{
	int quantity;
	int next;
	T** storage;
	void inflate(int increase = inc);
public:
	PStash() : quantity(0), next(0), storage(0){}
	virtual ~PStash();
	int add(T* t);
	T* operator[](int);
	T* remove(int);
	int count() const { return next; }
};
template<class T, int inc>
void PStash<T, inc>::inflate(int increase)
{
	quantity += increase;
	T** temp = new T*[quantity];
	for(int i = 0; i < next; i++)
	{
		temp[i] = storage[i];
	}
	for(int i = next; i < quantity; i++)
	{
		temp[i] = 0;
	}
	delete []storage;
	storage = temp;
}
template<class T, int inc>
int PStash<T, inc>::add(T* t)
{
	if(quantity == 0 || next == quantity)
	{
		inflate(inc);
	}
	storage[next++] = t;
	return next-1;
}
template<class T, int inc>
T* PStash<T, inc>::operator[](int index)
{
	if(index < 0 || index >= next)
	{
		return 0;
	}
	return storage[index];
}

template<class T, int inc>
T* PStash<T, inc>::remove(int index)
{
	T* temp = storage[index];
	if(storage[index] != 0)
	{
		delete storage[index];
		storage[index] = 0;
	}
	return temp;
}
template<class T, int inc>
PStash<T, inc>::~PStash()
{
	int	j = 0;
	for(int i = 0; i < next; i++)
	{
		if(storage[i] != 0)
		{
			delete storage[i];
			j++;
		}
	}
	cout << "In ~PStash(), delete num = " << j << endl;
	delete []storage;
}

#endif //TEMPLATE_POINTER_STASH
