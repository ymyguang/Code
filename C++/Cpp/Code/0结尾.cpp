#include <stdio.h>

int main()
{
	unsigned int num[100][100],t[100];
	int j = 1,x;
	int f_2 = 1;
	while (f_2)
	{
		scanf("%d",&x);
		if (x != 0) {
			num[j][0] = x;  //存放十进制数字
			j++;
		}
		else 
			f_2 = 0;        //如果字符串为0，结束输入 
	}
	
	
	for (int ii = 1; ii < j;ii++)   //遍历十进制的所有数字，无其他意义 
	{
		int i = 1 ,a;
		int f = 0;
		while (num[ii][0] >= 0 && !f)
		{
			a = num[ii][0] % 2;
			num[ii][i] = a;    //ii代表带几个数字，代表是十进制中的二进制位的值 
			i++;
			num[ii][0] /= 2;
			if ( num[ii][0] == 0)
				f = 1;
		}
		t[ii]  = i - 1;       //该进制的二进制位数 
	}
	
	
	for (int n = 1; n < j; n++)   //遍历所有十进制 
	{
		for (int jj = t[n] ;jj > 0;jj--)   //遍历该数字的二进制 
		{
			printf("%d",num[n][jj]);
		}
		printf("\n");
	}
	return 0;
}
