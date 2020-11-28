#include "circle.h"

Circle::Circle() {
	r = 1.0;
}

Circle::Circle(double _r) {
	this->r = _r;
}

double Circle::getAaer() {
	return r * 3.14 * 3.14;
}