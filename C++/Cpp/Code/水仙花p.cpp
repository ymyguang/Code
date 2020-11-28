#include<math.h>
#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int a,b,sum=0,c;
	a = pow(10,x-1);
	for(a; a < pow(10,x);a++)
	{
		c=a;
		sum = 0;
		do
		{
		    b=a%10;
			a=a/10;
			sum=sum+pow(b,x);
		}while(a!=0);
		a = c;
	if(sum==c)
		printf("%d\n",c);
	}
}
