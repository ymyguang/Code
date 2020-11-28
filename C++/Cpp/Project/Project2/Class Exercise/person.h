#include <iostream>// 头文件声明
class Person
{
public:
	Person(int tall, int age, int ton);
	Person(Person& copyPerson);
	int m_tall;
	int m_age;
	int m_ton;
	int GetTall();
	int GetAge();
	int GetTon();
};
