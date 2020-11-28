#include "circle.h"
Circle::Circle() {
	r = 1.0;
}
Circle::Circle(double _r) {
	r = _r;
}
double Circle::getArea()
{
	return r * r * 3.14;
}
void Circle::changer(double r) {  //change r
	this->r = r;
}
double Circle::getR()const {  //get r
	return r;
}