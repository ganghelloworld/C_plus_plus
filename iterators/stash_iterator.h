#ifndef TEMPLATE_POINTER_STASH
#define TEMPLATE_POINTER_STASH

#include <iostream>

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

	class iterator
	{
		PStash& ps;
		int index;
	public:
		iterator(PStash& p, bool b = true) : ps(p)
		{
			if(b) index = 0;
			else index = ps.count() - 1;
		}
		iterator(iterator& it) : ps(it.ps), index(it.index){}
		T* operator++()
		{
			if(index >= 0 && index < ps.count() - 1)
			{
				return ps.storage[++index];
			}
			return NULL;
		}
		T* operator++(int)
		{
			if(index >= 0 && index < ps.count() - 1)
			{
				return ps.storage[index++];
			}
			return NULL;
		}
		T* operator--();
		T* operator--(int);
		iterator& operator+=(int step)
		{
			if(index + step >= 0 && 
				index + step < ps.count() - 1)
				index += step;
			return *this;
		}
		iterator operator+(int step)
		{
			iterator ret(*this);
			ret += step;
			return ret;
		}
		bool operator==(iterator& it) const { return (index == it.index); }
		bool operator!=(iterator& it) const { return (index != it.index); }
		iterator& operator=(iterator& it)
		{
			ps = it.ps;
			index = it.index;
			return *this;
		}
		T* operator*() const
		{
			return current();
		}
		T* operator->() const
		{
			return current();
		}
		T* current()
		{
			if(index >= 0 && index < ps.count())
				return storage[index];
			return NULL;
		}
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this, false); }
};
template<class T, int inc>
T* PStash<T, inc>::iterator::operator--()
{
	if(index >= 1 && index < ps.count())
	{
		return ps.storage[--index];
	}
	return NULL;
}
template<class T, int inc>
T* PStash<T, inc>::iterator::operator--(int)
{
	if(index >= 1 && index < ps.count())
	{
		return ps.storage[index--];
	}
	return NULL;
}
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
	std::cout << "In ~PStash(), delete num = " << j << std::endl;
	delete []storage;
}

#endif //TEMPLATE_POINTER_STASH
