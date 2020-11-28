#include <stdio.h>
int main()
{
	int x,a,b,c,d,e;
	scanf("%d",&x);
	a=x/10000;
	b=(x/1000)%10;
	c=(x/100)%100%10;
	d=(x/10)%1000%100%10;
	e=x%10000%1000%100%10;
	printf("%d %d %d %d %d\n",a,b,c,d,e);
	return 0;
}