#ifndef AUTO_COUNTER_H
#define AUTO_COUNTER_H

#include <iostream>
#include <set>
#include <string>

class AutoCounter
{
	static int count;
	int id;
	AutoCounter() : id(count++)
	{
		verifier.add(this);
		std::cout << "created[ " << id << " ]" << std::endl;
	}
	AutoCounter(const AutoCounter&);
	void operator=(const AutoCounter&);
public:
	class CleanupCheck
	{
		std::set<AutoCounter*> traces;
	public:
		void add(AutoCounter* ap)
		{
			traces.insert(ap);
		}
		void remove(AutoCounter* ap)
		{
			if(traces.erase(ap) != 1)
			{
				std::cout << "Attemp delete twice" << endl;
			}
		}
		~CleanupCheck()
		{
			std::cout << "~CleanupCheck()" << std::endl;
			if(traces.size() != 0)
			{
				std::cout << "AutoCounter object not cleaned up" << std::endl;
			}
		}
	};
	static CleanupCheck verifier;
	static AutoCounter* create()
	{
		return new AutoCounter();
	}
	~AutoCounter()
	{
		std::cout << "destorying[ " << id << " ] " << std::endl;
		verifier.remove(this);
	}
	friend std::ostream& operator<<(
				std::ostream& os, const AutoCounter& ac)
	{
		return os << "AutoCounter " << ac.id;
	}
	friend std::ostream& operator<<(
				std::ostream& os, const AutoCounter* ac)
	{
		return os << "AutoCounter " << ac->id;
	}
};
int AutoCounter::count = 0;
AutoCounter::CleanupCheck AutoCounter::verifier;
#endif //AUTO_COUNTER_H
