#include <iostream>
using namespace std;
int main()
{
	int l,n,tree[100001];
	cin >> l >> n;
	for (int ii = 0;ii <= l;ii++) tree[ii]  = 1;//数组清空  另一种方式  memset(tree,1,sizeof(tree)); 
	for (int i = 1;i <= n;i++)
	{
		int frist,last;
		cin >> frist >> last;
		for (int temp = frist ; temp <= last; temp++)
			tree[temp] = 0;
	 } 
	 int ans = l;
	 for (int j = 0; j <= l;j++)
	 {
	 	if (tree[j] == 0)  ans--;
	 }
	cout <<ans+1;
	return 0;
 } 
