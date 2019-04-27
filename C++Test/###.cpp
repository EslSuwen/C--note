#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int i, j;
	for (i = 1; i < 6; i++)
	{
		for (j = 1; j <= (12 - 2 * i); j++)
		{
			if (i == 1 && j != 10)
				cout << "#";
			else if (i == 1 && j == 10)
				cout << "#" << endl;
			else
			{
				if (j == 1)
					cout << setw(i) << "#";
				if (j == (12 - 2 * i))
					cout << "#" << endl;
				if (j > 1 && j < (12 - 2 * i))
					cout << "*";
			}
		}
	}
	return 0;
}