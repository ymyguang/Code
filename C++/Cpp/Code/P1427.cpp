#include <iostream>
using namespace std;

int main()
{
	long x,	figer[101];
	int i = 1;

	while (1)
	{
		cin >> x;
		if (x)  
		{
			figer[i] = x;  i++;
		}
		else {
			for (int j = i-1 ;j >= 1;j--)
				cout << figer[j]<< " ";
			break;
		}	
	}
	return 0;
 } 
