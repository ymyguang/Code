// 排序算法——冒泡排序
// 时间复杂度：On2

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

	cout << "数组地址"  << &a << endl; 
	show_arr(a,sizeof(a)/4); 
//注意点：将数组作为一个参数传出去，那么他就会“退化”成一个指针类型，进而失去“数组的属性”。(这里的数组这的是系统自动生成的) 
//因此通过传数组指针，将丢失数组的属性，那么数组的长度则需要重新定义一个长度变量传给数组； 
 } 
 
 
void show_arr(int *pA, int len)
 {
 	cout << "指针地址" << pA; 
// 	for (int jj = 0 ;jj < len ;jj++)
//		cout<< pA[jj] << " ";  //这里的pA本身就是一个地址，没有必要再去取地址。 
 }
