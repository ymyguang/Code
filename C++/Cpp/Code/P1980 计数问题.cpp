/*
数学方法，拆解数字*（法一） 
#include <iostream> 
using namespace std;
int main(void)
{
	int n,x,ans;
	cin >> n >> x;
	for (int i = 1 ; i <= n;i++)
	{
		int b = i;
		while (b)
		{
			int c = b%10;
			if (c==x)  ans++;
			b = b/10;
		}
	}
	cout << ans;
	return 0;
}*/
// 法二：字符串
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main()
{
	char temp[10001];  //保证空间的大小，如果直接使用string s 可能会导致空间不够，导致报错！ 
	int n,x,ans;
	cin >> n >> x;
	for (int i =1;i <= n;i++)
	{
		sprintf(temp,"%d",i);  //int 转 char  类型 
		string s(temp);        //将字符数组的指针地址付给s，其就是让两者相等，从而利用字符串函数 s.size();检测字符串大小。 
		for (int j = 0;j < s.size();j++)
		{
			if (s[j]-'0' == x)
			ans++;
		}
	}
	cout << ans;
	return 0;
 } 
