#include <iostream>

using	std::cout;
using	std::endl;

int main() {
	const int x = 112;
	int* pc = &x;
	*pc = 12;
	cout << "x = " << x << endl << "pc = " << *pc << endl;
	cout << "�任��X = " << x;
	return 0;
}