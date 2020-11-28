//initializer_list的作用：为解决传递参数数量不唯一，通过initailizer_list创建临时对象，将参数值传递给函数
//使用方法：{}当，使用花括号的时候编译器就会自己创建一个临时对象，传递给函数；
//2020年4月13日
//By ymyguang
#include <iostream>
void print(std::initializer_list<int> list) {
	//To imitate printf,but this is a bug that only printf simple size valliable;

	for (auto it = list.begin(); it != list.end(); it++) {
		std::cout << *it << " ";
		//The "*" can konw that list add is a per;
	}
	std::cout << std::endl;
}

int main() {
	print({ 1, 2, });
}