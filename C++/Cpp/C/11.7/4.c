#include<stdio.h>

int sum(int x, int y)
{
	int c;
	c = x + y;
	return c;
}

int main() {
	int n;
	int a[3][3],b[3][3],t[3][3];
	printf("������n��ֵ��");
	scanf("%d",&n);
	printf("������A��");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&a[i][j]);
	printf("������B��");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&b[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[i][j] = sum(a[i][j], b[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", t[i][j]);
		}

		printf("\n");
	}
}