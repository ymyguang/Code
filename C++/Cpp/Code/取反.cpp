//λ�������~ ��ȡ����
//˵���������ڼ���������Բ������ʽ���ڵġ���ȡ������ȡ���������λ��ȥ�෴��������λ���⣡ 




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
