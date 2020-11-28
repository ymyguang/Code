#include <iostream>
//#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	int n,fish[101],sum[101];
	
	memset(sum,0,sizeof(sum));
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> fish[i];
	}
	for (int ii = 1; ii <= n;ii++) 
	{
		for (int j = 1;j < ii;j++)
		{
			if (fish[ii] > fish[j]) sum[ii]++;
		}
	}
	for (int jj = 1;jj <= n;jj++)
		cout << sum[jj] << " ";
	return 0;
 } 
 
