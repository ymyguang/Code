#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n,sum[101],a[101];
	int ans = 0;
	memset(a,0,sizeof(a));//全部变成0 ，目的是为了表示数字是否重复 
	//初始化变量，准备 
	cin >> n;
	for (int ii = 1; ii <= n;ii++)
		cin >> sum[ii];

	sort (sum+1,sum+n+1);  // sort排序，默认的是从小到大排列~！       特 别注意哈：   sort函数的头文件是 #include <cstring> 
	for (int j = 3;j <= n;j++)
	{
		for (int x = 1; x < j-1 ;x++)   //边界可以稍微优化一下。但是我测试的时候基本上不影响结果！ 
			for (int i = x+1; i < j ;i++)
			{
				if (sum[x] + sum[i] > sum[j])  break;  //因为是从小到大，所以只要两个相邻的数字之和大于目标数字，就退出循环，进行下一个数字的判断 ，故break！ 
				if ((sum[j] == sum[x] + sum[i])&&(sum[x] != sum[i])&&(a[j] == 0)) //一开始一直不能a，回头看了看题，才发现重复的不能计数！这里的a数组就是判断是否计过数 
				{
					a[j] = 1; //对满足的数字标记 
					ans ++;
					break; //既然得到了这个满足的数字，跳出循环，对下一个数字进行判断！ 
				 } 
			}
	}
	cout << ans;  //最后输出结果 
	return 0;
}
