#include <stdio.h>

int main()
{
	int x;
	while (scanf("%d",&x) && x != 0)
	{
		int i = 1 ,a;
		int f = 0;
		int arrmy[10000] = {0};
		while (x >= 0 && !f)
		{
			a = x % 2;
			arrmy[i++] = a;
			x = x / 2;
			if ( x == 0)
				f = 1;
		}
		for (int j = i - 1; j > 0;j--)
			printf("%d",arrmy[j]);
	}
	return 0;
}
