#include <iostream>
using namespace std;


int main()
{
	long long n, maxi = 0, ans = 1;
	long long t[1000001]; 

	cin >> n;
	cin >> t[1];
	for (int i = 2;i <= n;i++)
	{
		cin >> t[i];
		if (t[i] > t[i-1])  ans++;
		else if (maxi < ans)
		{
			maxi = ans;	 ans = 1;
		}
		else ans = 1;  //��һ�������� ������ʼ��ά����ǰ�������������� 
	}
	cout << maxi;	 
	return 0;
 } 
