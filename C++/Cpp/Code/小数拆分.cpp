#include "stdio.h"
double num;
int x;
double y;

double chai(double num)
{
	x = (int)num;
	y = num - x;
}

int main()
{
	while (~scanf("%lf",&num)){
		chai (num);
		printf("%d %lf",x,y);
	}
	return 0;
 } 
