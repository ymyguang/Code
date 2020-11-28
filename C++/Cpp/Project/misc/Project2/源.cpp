#include <cstdio>
#include <cstring>
struct employee {
	char name[15];
	char sex;
	int age;
	float salary;
};

int main() {
	struct employee emp1 = { "tina",'f',18, 4000 }, emp2, emp3, emp4;
	emp2 = emp1;
	strcpy_s(emp3.name, " Smith");//gets (emp3. name)
	emp3.sex = 'm';
	emp3.age = 20;
	emp3.salary = 4000;
	int a;
	scanf_s("%s%d%c%f", emp4.name, &emp4.age, &emp4.sex, &emp4.salary);
	printf("姓名: %s性别: %c年龄: %d薪资: %.2f\n", emp1.name, emp1.sex, emp1.age, emp1.salary);
	printf("姓名: %s性别: %c年龄: %d薪资: %.2f\n", emp2.name, emp2.sex, emp2.age, emp2.salary);
	printf("姓名: %s性别: %c年龄: %d薪资: %.2f\n", emp3.name, emp3.sex, emp3.age, emp3.salary);
	printf("姓名: %s性别: %c年龄: %d薪资: %.2f\n", emp4.name, emp4.sex, emp4.age, emp4.salary);
}