#include "circle.h"
#include <iostream>
using std::endl;

//void print(Circle c) {
//	std::cout << c.getAaer() << endl;
//}
//

void print(Circle& c) {
	std::cout << c.getAaer() << endl;
}

void print(Circle* c) {
	std::cout << c->getAaer() << endl;
}

int main() {
	//Circle o = print(Circle{ 3.2 });
	Circle ca[] = { 1.0, 2.0,3.0 };
	print(ca[0]);
	print(ca + 2);
	return 0;
}