#ifndef STATIC_H
#define STATIC_H

class A
{
	static int count;
	int id;

	class B
	{
		int bid;
	public:
		B(){}
		void set_id(int t){ bid = t; }
		int get_id(){ return bid; }
	};

	static B b;
public:
	//class B;
	A() : id(count++){}
	int get_count()
	{
		return id;
	}
	void set_bid(int a)
	{
		b.set_id(a);
	}
	int get_bid()
	{
		return b.get_id();
	}
};
int A::count = 0;
A::B A::b;
#endif //STATIC_H
