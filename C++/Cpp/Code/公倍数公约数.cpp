#include <stdio.h>
int main()
{	
	int m,n,r,x,y;
	scanf("%d%d",&x,&y);
	m = x;
	n = y;
	if (n > m)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	r = m%n;
	while (r!=0)
	{
		m = n;
		n = r;	
		r = m%n;
	}
	printf("���Լ��Ϊ��%d\n�� С������Ϊ��%d",n,x*y/n);

}

