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
	
	for (int j = 1; j <= i - 1;j++)  //�������з�Χ 
	{
		ans = 0;
		for (int star = m[j]; star <= n[j]; star++)  //������Χ�ڵ����� 
		{

				int min = star % 10;           //����λ�� 
				int mid = star / 10 % 10;      //�ڶ�λ�� 
				int max = star / 10 / 10 % 10; //��һλ�� 
				if (pow(min,3) + pow(mid,3) + pow(max,3) == star)
					ans++;
		 } 
		 printf("%d\n",ans);
	}
	return 0;
}
