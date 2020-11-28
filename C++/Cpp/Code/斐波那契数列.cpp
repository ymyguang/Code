#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[1000];
	a[1] = 0,a[2] = 1;
	cin >> n;
	cout << "0 " << "1 " ;
	
	for (int i=3;i<=n;i++)
	{
		a[i] = a[i-1]+a[i-2];
		cout << a[i]  << " "; 
	}
	return 0;
 } 
