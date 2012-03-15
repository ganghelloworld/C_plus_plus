#include "stash.h"
#include <iostream>
#include <cassert>

using namespace std;

const int increment = 100;

int Stash::add(void *element)
{
	if(next >= quantity) inflate(increment);	

	int start_bytes = next * size;
	unsigned char* s = (unsigned char *)element;
	for(int i = 0; i < size; i++)
	{
		storage[start_bytes + i] = s[i];
	}
	next ++;
	return (next - 1);
}

void Stash::inflate(int increase)
{
	assert(increase >= 0);
	if(increase == 0) return;
	int new_quantity = quantity + increase;
	int new_bytes = new_quantity * size;
	int old_bytes = quantity * size;
	unsigned char *b = new unsigned char[new_bytes];
	for(int i = 0; i < old_bytes; i++)
	{
		b[i] = storage[i];
	}
	delete [](storage);
	storage = b;
	quantity = new_quantity;
}
