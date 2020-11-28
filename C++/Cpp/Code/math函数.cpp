#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{
	int a,b,c,d,e;  //floor()向下取整，ceil 向上取整 
	a = sqrt(pow(sin(15),2.5));   //pow()作用是取x的y次幂 
	b = 8*log(2*PI);              //表示为pow(x,y)；sqrt() 作用是开根号 
	c = abs(pow(6,2.5) - 3*cos(30)); //abs()作用取绝对值 
	d = a/b + c;
	printf("%d",d);
	return 0;
 } 
 
//温故知识点  #define  这里是定义变量
//知识点二，math头文件里面的函数，以上备注是比较常用的 
