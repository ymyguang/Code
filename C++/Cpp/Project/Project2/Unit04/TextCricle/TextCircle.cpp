#include <iostream>
using std::cin;
using std::cout;
using std::endl;
class Circle {
public:
	double radius;
	Circle() {
		radius = 1.0;
	}
	Circle(double r) {
		radius = r;
	}
	double getArea() {
		return (3.14 * radius * radius);
	}
};

int main() {
	Circle c1;
	Circle c2{ 2.0 };

	cout << c1.getArea() << endl;
	cout << c2.getArea() << endl;

	return 0;
}