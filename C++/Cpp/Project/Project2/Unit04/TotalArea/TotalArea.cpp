#include <iostream>
#include "circle.h"
#include "io.h"

int main() {
	Circle c1[]{ 1.0,2.0,3.0 };
	//Circle c2[]{ 4.0,5.0,6.0 };
	cout << "ÿ��Բ�ı߳���\n";
	auto area{ 0.0 };
	for (auto x : c1) {
		cout << x.getR() << endl;
		area += x.getArea();
	}
	cout << "���������Բ�����" << area;
	return 0;
}