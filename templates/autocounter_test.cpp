#include "template_pointer_stash.h"
#include "auto_counter.h"
#include <iostream>

int main()
{
	PStash<AutoCounter, 10> ac_ps;
	
	for(int i = 0; i < 12; i++)
	{
		ac_ps.add(AutoCounter::create());
	}
	for(int i = 0; i < 6; i++)
	{
		ac_ps.remove(i);
	}
}
