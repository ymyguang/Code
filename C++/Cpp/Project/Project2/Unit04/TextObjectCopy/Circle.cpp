#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Square {
private:
	double side = 1.0;
public:
	Square(double side) {
		this->side = side;
	}
	Square() = default; //C++11 ǿ�Ʊ���������Ĭ�Ϲ��캯��

	double getArea() {
		return side * side;
	}
};

int main() {
	Square s1, s2{ 1.3 };
	cout << s1.getArea() << endl;
	cout << s2.getArea() << endl;

	s1 = s2;

	cout << s1.getArea() << endl;
	cout << s2.getArea() << end
		return 0;
}