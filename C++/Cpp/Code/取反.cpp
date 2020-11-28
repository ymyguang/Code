//位运算符：~ （取反）
//说明：数字在计算机中是以补码的形式存在的。故取反就是取补码的所有位数去相反数。符号位除外！ 




#include <stdio.h>
int x[10000],y[10000];
int main()
{
	int i = 1,sum = 0;
	int m,n;
	while (scanf("%d%d",&m,&n) != -1)
	{
		if (m > n)
		{
			int temp = m;
			m = n;
			n = temp;
		}
		x[i] = m;
		y[i] = n;
		i++;
	}
	
	for (int ii = 1 ;ii <= i - 1;ii++)
	{
		sum = 0;
		for (int j = x[ii]; j <= y[ii];j++)
		{
			if (j % 5 == 0 && j % 3 == 0 )
				sum = sum + j;
		}
		printf("%d\n",sum);
	}
	return 0;
}
