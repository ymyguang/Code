/*
��ѧ�������������*����һ�� 
#include <iostream> 
using namespace std;
int main(void)
{
	int n,x,ans;
	cin >> n >> x;
	for (int i = 1 ; i <= n;i++)
	{
		int b = i;
		while (b)
		{
			int c = b%10;
			if (c==x)  ans++;
			b = b/10;
		}
	}
	cout << ans;
	return 0;
}*/
// �������ַ���
#include <iostream>
#include <cstdio>
#include <cstdlib> 
using namespace std;
int main()
{
	char temp[10001];  //��֤�ռ�Ĵ�С�����ֱ��ʹ��string s ���ܻᵼ�¿ռ䲻�������±��� 
	int n,x,ans;
	cin >> n >> x;
	for (int i =1;i <= n;i++)
	{
		sprintf(temp,"%d",i);  //int ת char  ���� 
		string s(temp);        //���ַ������ָ���ַ����s���������������ȣ��Ӷ������ַ������� s.size();����ַ�����С�� 
		for (int j = 0;j < s.size();j++)
		{
			if (s[j]-'0' == x)
			ans++;
		}
	}
	cout << ans;
	return 0;
 } 
