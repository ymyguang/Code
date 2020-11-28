#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	//常量声明
	const int x = 43;
	//常量不可变
	//x = 32; “x”: 不能给常量赋值

	//  常量指针所指的数据不可变
	int y = 2;
	const int* p = &x;
	//  (*p) = 22; “p”: 不能给常量赋值
	const int* q = &y;
	//  (*q) = 5;

	//  指针常量不可变
	int* const r = &y;
	int z = 3;
	(*r) = 20;
	cout << *r << " " << y << endl;
	//  常指针常量
	const int* const s = &y;
	//  char*

	int zx = 0, * const px = &zx;
	cout << zx << endl;
	*px = 21;
	cout << zx;

	return 0;
}