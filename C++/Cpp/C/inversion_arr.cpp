#include <iostream>
using namespace std;
//sizeof()���ж�����ĳ��� 
int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

int main()
{
//############ forѭ��  ###########
//	for(int i = 0 ;i <= sizeof(a)/4/2;i++)
//	{
//		int tem = a[i];
//		a[i] = a[sizeof(a)/4-i-1];
//		a[sizeof(a)/4-i-1] = tem;
//	}

//############ ˫ָ�� #############
	int i = 0;
	int j = sizeof(a)/4 - 1;  //�������һ����Ч��ַ�±�
	while (i < j) {
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++; j--;
	} 

//########### ������� ############## 
	for(int j = 0;j < sizeof(a)/4;j++){
		cout << a[j] << " ";
	}
	return 0; 
 } 
