//最小公倍数和最大公约数 (两个数的)
#include <stdio.h>
int a,b,i,e,minn,maxx;

int main()
{
	printf("请输入两个数值："); 
	scanf("%d%d",&a,&b);
	if (a < b)
	{
		minn = a;
		maxx = b;
	 } 
	else {
		minn = b;
		maxx = a;
	 }
	for (i = minn; ;i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("最大公约数为：%d\n",i);
			break;
		}
	}
	for (e = maxx; ;e++)
	{
		if (e%a == 0 && e%b == 0)
		{
			printf("最小公倍数为：%d",e);
			break;
		}
	}
	return 0;
 } 
 
 
 
 
 
 

 
 //最小公倍数和最大公约数 (任意数)
#include <stdio.h>
 //定义 
int a,b,i,e,c,n,minn = 9999,maxx = -111,sum;
int num[110];
 //判断 
void panduan(int x)  //取最值 
{
	if (x < minn) 
		minn = x;
	if (x > minn) 
		maxx = x;
}

int main()
{
	int nn;
	scanf("%d",&nn);
	for (int iii = 1; iii <= nn;iii++)  //总循环次数 
	{
		//初始化 
		minn = 9999,maxx = -111,sum = 0 ;       //重置极值 
		num[110] = {0};              //初始化数字 
 		//输入 
	 	scanf("%d",&n);                //输入数字的个数 
		for (int ii = 1; ii <= n;ii++)  //开始输入 
		{
			int y;
			scanf("%d",&y);     //读取每一个值
			num[ii] = y;		//存入数组 
			panduan(y);         //给函数 
		}
		
		//计算   最大公约数 
		for (i = minn; ;i--)
		{
			sum = 0;
			for (int j = 1;j <=n ;j++)     //验证每个数是否能整除此数 
				sum = sum + num[j] % i ; 
			if (sum == 0)
			{
				printf("最大公倍数%d\n",i);
				break;
			}
		}
		//计算最小公倍数 
	 	for (e = maxx; ;e++)
		{
			sum = 0; 
			for (int j = 1;j <= n ;j++)     //验证每个数是否被次数整除
				sum = sum + e % num[j]; 
			if (sum == 0)
			{
				printf("最小公倍数为：%d",e);
				break;
			}
		}
		}
	return 0;
 } 

