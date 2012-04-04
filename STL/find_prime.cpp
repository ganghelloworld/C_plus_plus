#include <iostream>
#include <string>

using namespace std;
static const int NUM = 50;
int main()
{
	string sieve(NUM, 'P');
	sieve.replace(0, 2, "NN");
	
	for(int i = 2; i < (sieve.size() / 2 - 1); i++)
	{
		for(int factor = 2; factor * i < sieve.size(); factor++)
		{
			sieve[factor*i] = 'N';
		}
	}
	cout << "Prime : " << endl;
	int i = sieve.find('P');
	while(i < sieve.size())
	{
		cout << i << " ";
		i++;
		i = sieve.find('P', i);
	}
	cout << endl;
	cout << "Not Prime : " << endl;
	i = sieve.find_first_not_of('P');
	while(i < sieve.size())
	{
		cout << i << " ";
		i++;
		i = sieve.find_first_not_of('P', i);
	}
	cout << endl;
}
