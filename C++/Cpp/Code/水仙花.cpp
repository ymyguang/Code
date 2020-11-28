#include <stdio.h>
#include <math.h> 

int main()
{
	int x,y,i = 1,ans = 0;
	int m[20],n[20];
	while (1)
	{
		scanf("%d%d",&x,&y);
		if (x == y && y == 0)
			break;
		else {
			m[i] = x;
			n[i] = y;
			i++;			
		}
	}
	
	for (int j = 1; j <= i - 1;j++)  //遍历所有范围 
	{
		ans = 0;
		for (int star = m[j]; star <= n[j]; star++)  //遍历范围内的数字 
		{

				int min = star % 10;           //第三位数 
				int mid = star / 10 % 10;      //第二位数 
				int max = star / 10 / 10 % 10; //第一位数 
				if (pow(min,3) + pow(mid,3) + pow(max,3) == star)
					ans++;
		 } 
		 printf("%d\n",ans);
	}
	return 0;
}
