#include <iostream>
using namespace std;
int main() {
	char str1[60], str2[60], *p1, * p2;
	gets(str1); p1 = str1;
	gets(str2); p2 = str2;
	while (*p1 != '\0') {
		p1++; 
	}
	while (*p2!='\0') {
		*p1++ =  *p2++;
	}
	*p2 = '\0'; 
	cout << str1;	
	return 0;
}

