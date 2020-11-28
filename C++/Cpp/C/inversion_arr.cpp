#include <iostream>
using namespace std;
//sizeof()来判断数组的长度 
int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

int main()
{
//############ for循环  ###########
//	for(int i = 0 ;i <= sizeof(a)/4/2;i++)
//	{
//		int tem = a[i];
//		a[i] = a[sizeof(a)/4-i-1];
//		a[sizeof(a)/4-i-1] = tem;
//	}

//############ 双指针 #############
	int i = 0;
	int j = sizeof(a)/4 - 1;  //数组最后一个有效地址下标
	while (i < j) {
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++; j--;
	} 

//########### 输出数组 ############## 
	for(int j = 0;j < sizeof(a)/4;j++){
		cout << a[j] << " ";
	}
	return 0; 
 } 
