#include <iostream>
void swap(int* x, int* y) {
	int t = 0;
	t = *x; *x = *y; *y = t;
}

int main() {
	int a = 1, b = 42;
	std::cout << a << " " << b << std::endl;
	swap(&a, &b);
	std::cout << a << " " << b;

	return 0;
}