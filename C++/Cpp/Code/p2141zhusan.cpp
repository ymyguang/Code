#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n,sum[101],a[101];
	int ans = 0;
	memset(a,0,sizeof(a));//ȫ�����0 ��Ŀ����Ϊ�˱�ʾ�����Ƿ��ظ� 
	//��ʼ��������׼�� 
	cin >> n;
	for (int ii = 1; ii <= n;ii++)
		cin >> sum[ii];

	sort (sum+1,sum+n+1);  // sort����Ĭ�ϵ��Ǵ�С��������~��       �� ��ע�����   sort������ͷ�ļ��� #include <cstring> 
	for (int j = 3;j <= n;j++)
	{
		for (int x = 1; x < j-1 ;x++)   //�߽������΢�Ż�һ�¡������Ҳ��Ե�ʱ������ϲ�Ӱ������ 
			for (int i = x+1; i < j ;i++)
			{
				if (sum[x] + sum[i] > sum[j])  break;  //��Ϊ�Ǵ�С��������ֻҪ�������ڵ�����֮�ʹ���Ŀ�����֣����˳�ѭ����������һ�����ֵ��ж� ����break�� 
				if ((sum[j] == sum[x] + sum[i])&&(sum[x] != sum[i])&&(a[j] == 0)) //һ��ʼһֱ����a����ͷ���˿��⣬�ŷ����ظ��Ĳ��ܼ����������a��������ж��Ƿ�ƹ��� 
				{
					a[j] = 1; //����������ֱ�� 
					ans ++;
					break; //��Ȼ�õ��������������֣�����ѭ��������һ�����ֽ����жϣ� 
				 } 
			}
	}
	cout << ans;  //��������� 
	return 0;
}
