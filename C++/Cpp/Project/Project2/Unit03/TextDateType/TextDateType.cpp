#include <iostream>
using std::cout;
using std::endl;
int main() {
	int x{ 1 };
	cout << x << endl;

	//强制类型转换
	cout << 1 / 2 << endl;
	cout << static_cast<double>(1) / 2 << endl;
	cout << static_cast<double>(1 / 2);

	cout << 1.f / 2.f << endl;
	return 0;
}