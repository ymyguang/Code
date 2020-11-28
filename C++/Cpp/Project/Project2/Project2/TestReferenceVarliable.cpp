#include <iostream>

int main() {
	int x = 0;
	int y{ 10 };
	int& rx = x;
	rx = 8;

	const char* s = "Hello";
	const char* t = "World";

	const char*& r = s; //∞Û∂®¡À
	r = t;
	std::cout << r;
	std::cout << s;
	return 0;
}