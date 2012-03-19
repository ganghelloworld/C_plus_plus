#include <fstream>
#include <string>

using namespace std;

ofstream out("HowMany.out");

class HowMany
{
	string name;
	static int object_count;
public:
	HowMany(const string& id = "") : name(id)
	{
		object_count++;
		print("HowMany()");
	}
	HowMany(const HowMany& h) : name(h.name)
	{
		name += " copy";
		object_count++;
		print("in copy_constructor");
	}
	void print(const string& msg)
	{
		if(msg.size() != 0) out << msg << ": ";
		out << "name = " << name << "\t"
			<< "object_count = " << object_count << endl;
	}
	~HowMany()
	{
		object_count--;
		print("~HowMany()");
	}
};

int HowMany::object_count = 0;

HowMany f(HowMany x)
{
	x.print("x argument inside f()");
	return x;
}

int main()
{
	HowMany h("h");
	h.print("after construction of h");
	HowMany h2 = h; 
	h2.print("after call f()");

	HowMany h3 = f(h);
	f(h);
}
