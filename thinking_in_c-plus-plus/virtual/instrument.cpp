#include <iostream>
using namespace std;
enum note {middle_c, c_sharp, c_flat};

class Instrument
{
	int a;
public:
	virtual void play(note n) const = 0;
};
void Instrument::play(note n) const
{
	cout << "Instrument::play()" << endl;
}

class Wind : public Instrument
{
public:
	void play(note n) const
	{
		cout << "Wind::play()" << endl;
	}
};

class Flute : public Wind
{
public:
	void play(note n) const
	{
		cout << "Flute::play()" << endl;
	}
};
void tune(Instrument&  i)
{
	i.play(middle_c);
}

int main()
{
	Instrument* w[] = {new Wind, new Flute};
	tune(*w[0]);
	tune(*w[1]);
}
