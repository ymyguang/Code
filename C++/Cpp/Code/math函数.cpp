#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{
	int a,b,c,d,e;  //floor()����ȡ����ceil ����ȡ�� 
	a = sqrt(pow(sin(15),2.5));   //pow()������ȡx��y���� 
	b = 8*log(2*PI);              //��ʾΪpow(x,y)��sqrt() �����ǿ����� 
	c = abs(pow(6,2.5) - 3*cos(30)); //abs()����ȡ����ֵ 
	d = a/b + c;
	printf("%d",d);
	return 0;
 } 
 
//�¹�֪ʶ��  #define  �����Ƕ������
//֪ʶ�����mathͷ�ļ�����ĺ��������ϱ�ע�ǱȽϳ��õ� 
