#include <iostream>
using std::cin;
using std::cout;
using std::endl;
auto foo(int arg) {
	return arg;
}
int main() {
	//auto x{ 111 };
	if (auto x = foo(111); x > 100) {
		cout << "big" << endl;
	}
	else {
		cout << "small";
	}
	int x = 1;
	return 0;
}