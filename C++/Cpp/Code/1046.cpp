	#include <iostream>
	using namespace std;
	
	int main()
	{
		int tree[10+1],x,ans = 0;
		
		for (int i = 1;i <= 10 ;i ++)
		{
			cin >>tree[i];
		}
		cin >> x;
		for (int j = 1;j <= 10;j++)
		{
			if (tree[j]-30 <= x)
				ans++;
		}
		cout << ans;
		
		return 0;
	 } 
