#include <stdio.h>

int main()
{
	unsigned int num[100][100],t[100];
	int j = 1,x;
	int f_2 = 1;
	while (f_2)
	{
		scanf("%d",&x);
		if (x != 0) {
			num[j][0] = x;  //���ʮ��������
			j++;
		}
		else 
			f_2 = 0;        //����ַ���Ϊ0���������� 
	}
	
	
	for (int ii = 1; ii < j;ii++)   //����ʮ���Ƶ��������֣����������� 
	{
		int i = 1 ,a;
		int f = 0;
		while (num[ii][0] >= 0 && !f)
		{
			a = num[ii][0] % 2;
			num[ii][i] = a;    //ii������������֣�������ʮ�����еĶ�����λ��ֵ 
			i++;
			num[ii][0] /= 2;
			if ( num[ii][0] == 0)
				f = 1;
		}
		t[ii]  = i - 1;       //�ý��ƵĶ�����λ�� 
	}
	
	
	for (int n = 1; n < j; n++)   //��������ʮ���� 
	{
		for (int jj = t[n] ;jj > 0;jj--)   //���������ֵĶ����� 
		{
			printf("%d",num[n][jj]);
		}
		printf("\n");
	}
	return 0;
}
