#include <stdio.h>
#include <math.h>
int main()
{
	int n,k,f = 0,sum = 0;
	scanf("%d%d",&n,&k);
	for (int i = n;i >= 0;i--)  //��������ֵ 
	{
		f = 0;
		for (int j = 2;j <= sqrt(i);j++)   //��֤�Ƿ�Ϊ���� 
		{
		 	if(i % j == 0)  //�������� 
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
