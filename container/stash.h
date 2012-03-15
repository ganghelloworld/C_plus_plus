#ifndef STASH_H
#define STASH_H

class Stash
{
	int size;
	int quantity;
	int next;

	unsigned char *storage;
	void inflate(int increase);

public:
	Stash(int sz) : 
		size(sz), quantity(0), next(0), storage(0)
	{}

	Stash(int sz, int q) : 
		size(sz), quantity(0), next(0), storage(0)
	{
		inflate(q);
	}
	
	~Stash()
	{
		if(storage != 0)
			delete []storage;
	}
	
	int add(void * element);

	void* fetch(int index) const
	{
		if(index < 0 || index >= next) return 0;
		return &(storage[index * size]);
	}

	int count() const
	{
		return next;
	}
};
#endif
