#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
	auto xx{ "42" };
	auto n = int{ 2 };
	auto xxx = { 1, 2, 4 };
	auto x[] = { 1,2,3 };
	cout << typeid(xx).name() << endl;
	return 0;
}

/*
auto用法：
1.使用auto必须初始化变量值
2.auto的参数可以是变量，当不加：“&”时，变量的常量性质将会丢失，显然加上&，仍然会保持
变量的常量性质
3.为了代码的简洁性，以及为了方便维护，尽量使用auto
4.使用auto的同一行必须是同一类型值，否则报错；
5.同一行赋值方式要相同，不要既有直接赋值，又有拷贝复制；
定义变量的几种方式：
	const int n = 1;
	auto x = 1;  直接 auto x{1};拷贝
	auto n = int{ 2 };对要赋的值进行条件限制；
	auto& x = n; //保持n的常量性质，也就是n的一个别名，地址还是相同的

补充一下：	const int a;报错，原因是：const变量必须要有初始值；跟auto的规则一样！

注意:使用auto定义数组时：auto xxx[] ={ 1, 2, 4 };这种形式错误，正确的方式如下：
auto xxx = { 1, 2, 4 };即没有"[]"的修饰；
	原因：
*/