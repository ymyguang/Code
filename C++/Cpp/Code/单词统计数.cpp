#include <stdio.h>

int main()
{
	int sum[100]  = {0},i = 1;
	char c;
	while (1)
	{
		scanf("%c",&c);
		if (c != ' ' && c != '.')
			sum[i]++;
		else if (c == ' ')
			i += 1;
		else if (c =='.')
			break;
	} 
	for (int j = 1; j <= i;j++)
	{
		printf("%d ",sum[j]);
	}	
	return 0;
 } 
