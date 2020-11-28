#include <iostream> 
using namespace std;

int main()
{
	int i ,num[88],sum = 0;
	char x;
	for (int j = 1; j <= 13;j++)
	{
		cin >> x;
		if (0+'0' <= x&& x <= '0'+9)
		{
			num[i++] = x - '0'; 
		}
		else if (x == 'X') num[9] = 10; 
	}
	for (int i2 = 0 ;i2 < 9;i2++)
	{
		sum = num[i2]*(i2+1) + sum;
	}
	if (sum%11 == num[9])  cout <<"Right";
	else 
	{
		cout << num[0] << "-" << num[1] << num[2] << num[3] << "-"  <<num[4]<< num[5] << num[6]<< num[7] << num[8]<< "-" ; 
		if (sum%11 == 10) cout <<"X";
		else cout << sum%11;
	}

	return 0;
}
