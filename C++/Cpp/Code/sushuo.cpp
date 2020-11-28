#include <stdio.h>
#include <math.h>  //2ÊÇËØÊý°¡£¡£¡£¡£¡ 
int main()
{
	int n,ans;
	scanf("%d",&n);
	ans = n - 1;
	for (int i = 2; i <= n; i++ )
	{
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				ans--;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
 }
