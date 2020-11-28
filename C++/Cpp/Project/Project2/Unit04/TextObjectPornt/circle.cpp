#include "circle.h"

Circle::Circle() {
	r = 1.0;
}
Circle::Circle(double _r) {
	r = _r;
}
double Circle::getAear() {
	return r * r * 3.14;
}