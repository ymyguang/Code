#include <iostream>
#include "person.h"
using namespace std;

int main() {
	Person p1(1, 2, 4);
	Person p2(p1);
	cout << "P1  \n";
	cout << "m_tall" << p1.m_tall << endl;
	cout << "m_ton" << p1.m_ton << endl;
	cout << "m_age" << p1.m_age << endl;

	cout << "p2  \n";
	cout << "m_tall" << p2.m_tall << endl;
	cout << "m_ton" << p2.m_ton << endl;
	cout << "m_age" << p2.m_age << endl;

	return 0;
}