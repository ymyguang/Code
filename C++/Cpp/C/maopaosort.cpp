// �����㷨����ð������
// ʱ�临�Ӷȣ�On2

#include <iostream>
using namespace std;


int a[10]= {1,534343,354,5637,3,67,843,6,4,4337};
int t;

void show_arr(int *pA,int len);

int main()
{
	for (int i = 1; i < sizeof(a)/4; i++)
		for (int j =0 ; j < sizeof(a)/4 - i; j++)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}

	cout << "�����ַ"  << &a << endl; 
	show_arr(a,sizeof(a)/4); 
//ע��㣺��������Ϊһ����������ȥ����ô���ͻᡰ�˻�����һ��ָ�����ͣ�����ʧȥ����������ԡ���(��������������ϵͳ�Զ����ɵ�) 
//���ͨ��������ָ�룬����ʧ��������ԣ���ô����ĳ�������Ҫ���¶���һ�����ȱ����������飻 
 } 
 
 
void show_arr(int *pA, int len)
 {
 	cout << "ָ���ַ" << pA; 
// 	for (int jj = 0 ;jj < len ;jj++)
//		cout<< pA[jj] << " ";  //�����pA�������һ����ַ��û�б�Ҫ��ȥȡ��ַ�� 
 }
