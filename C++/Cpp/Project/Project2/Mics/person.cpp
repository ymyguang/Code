#include "D:\code\cpp\新建文件夹\Project2\Class Exercise\person.h"
Person::Person(int tall, int age, int ton)
{
	m_ton = ton;
	m_tall = tall;
	m_age = age;
}
Person::Person(Person& copyPerson) {
	m_age = copyPerson.m_age;
	m_tall = copyPerson.m_tall;
	m_ton = copyPerson.m_ton;
}
int Person::GetAge() {
	return m_age;
}
int Person::GetTall() {
	return m_tall;
}
int Person::GetTon() {
	return m_ton;
}