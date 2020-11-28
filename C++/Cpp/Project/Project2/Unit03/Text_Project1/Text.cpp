#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	char a[3], b[3];
	char* const p = a;
	*(p++) = 'b';
	p[0] = 'a';
	p[3] = b[0];
	return 0;
}