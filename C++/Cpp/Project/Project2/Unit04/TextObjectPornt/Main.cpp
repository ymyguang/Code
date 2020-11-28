//代码整理快捷方式：Ctrl+D
#include <iostream>
#include "circle.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
	auto* pc1 = new Circle{ 1.0 };
	Circle c3{ 2.0 };
	auto cp2 = &c3;
	auto c4 = new Circle[3]{ 1.0, 2.0, 3.0 };
	for (int i = 0; i < 3; i++)
	{
		cout << c4[i].getAear() << endl;
	}
	cout << (*pc1).getAear() << endl;
	cout << cp2->getAear() << endl;
	delete[]c4;
	//delete[]c4; //未初始化
	delete pc1;
	return 0;
}