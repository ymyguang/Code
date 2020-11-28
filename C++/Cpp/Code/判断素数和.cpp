#include <stdio.h>
#include <math.h>
int main()
{
	int n,k,f = 0,sum = 0;
	scanf("%d%d",&n,&k);
	for (int i = n;i >= 0;i--)  //遍历所有值 
	{
		f = 0;
		for (int j = 2;j <= sqrt(i);j++)   //验证是否为素数 
		{
		 	if(i % j == 0)  //不是素数 
		 	{
		 		f = 1;
		 		break;
			}
		}	
		if (f == 0 && k)
		{
			k--;
			sum += i;
			if (k != 0)
				printf("%d+",i);
			else printf("%d",i);
		}
	}
	printf("=%d",sum);
	return 0;
 } 
