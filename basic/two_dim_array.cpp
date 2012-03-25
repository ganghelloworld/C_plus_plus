#include <iostream>

using namespace std;

//static const int SIZE = 5;

int main()
{
	int SIZE = 5;
	int** two;
	two = new int*[2 * SIZE];
	for(int i = 0; i != 2 * SIZE; i++)
	{
		two[i] = new int[SIZE];
	}
	for(int i = 0; i != 2 * SIZE; i++)
	{
		for(int j = 0; j != SIZE; j++)
		{
			two[i][j] = SIZE * i + j;
			cout << two[i][j] << "\t";
		}
		cout << endl;
	}

	if(two != 0)
	{
		for(int i = 0; i != 2 * SIZE; i++)
		{
			if(two[i] != 0)
				delete []two[i];
		}
		delete []two;
		cout << "Delete success!" << endl;
	}
	return 0;
}
