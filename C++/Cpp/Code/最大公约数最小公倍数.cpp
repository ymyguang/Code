//��С�����������Լ�� (��������)
#include <stdio.h>
int a,b,i,e,minn,maxx;

int main()
{
	printf("������������ֵ��"); 
	scanf("%d%d",&a,&b);
	if (a < b)
	{
		minn = a;
		maxx = b;
	 } 
	else {
		minn = b;
		maxx = a;
	 }
	for (i = minn; ;i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("���Լ��Ϊ��%d\n",i);
			break;
		}
	}
	for (e = maxx; ;e++)
	{
		if (e%a == 0 && e%b == 0)
		{
			printf("��С������Ϊ��%d",e);
			break;
		}
	}
	return 0;
 } 
 
 
 
 
 
 

 
 //��С�����������Լ�� (������)
#include <stdio.h>
 //���� 
int a,b,i,e,c,n,minn = 9999,maxx = -111,sum;
int num[110];
 //�ж� 
void panduan(int x)  //ȡ��ֵ 
{
	if (x < minn) 
		minn = x;
	if (x > minn) 
		maxx = x;
}

int main()
{
	int nn;
	scanf("%d",&nn);
	for (int iii = 1; iii <= nn;iii++)  //��ѭ������ 
	{
		//��ʼ�� 
		minn = 9999,maxx = -111,sum = 0 ;       //���ü�ֵ 
		num[110] = {0};              //��ʼ������ 
 		//���� 
	 	scanf("%d",&n);                //�������ֵĸ��� 
		for (int ii = 1; ii <= n;ii++)  //��ʼ���� 
		{
			int y;
			scanf("%d",&y);     //��ȡÿһ��ֵ
			num[ii] = y;		//�������� 
			panduan(y);         //������ 
		}
		
		//����   ���Լ�� 
		for (i = minn; ;i--)
		{
			sum = 0;
			for (int j = 1;j <=n ;j++)     //��֤ÿ�����Ƿ����������� 
				sum = sum + num[j] % i ; 
			if (sum == 0)
			{
				printf("��󹫱���%d\n",i);
				break;
			}
		}
		//������С������ 
	 	for (e = maxx; ;e++)
		{
			sum = 0; 
			for (int j = 1;j <= n ;j++)     //��֤ÿ�����Ƿ񱻴�������
				sum = sum + e % num[j]; 
			if (sum == 0)
			{
				printf("��С������Ϊ��%d",e);
				break;
			}
		}
		}
	return 0;
 } 

