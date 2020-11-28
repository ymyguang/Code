#include <iostream>
#include <stdio.h>
#define	N 2
using namespace std;
struct Student
{
	char name[10];
	int year;
	int part;
	float studynum;
}a[N], b[N], * pa, * pb;

int main() {
	FILE* fp;
	pa = a;
	pb = b;
	int size = sizeof(Student);
	if ((fp = fopen("student.txt", "w+")) == NULL) {
		cout << "文件导入失败";
	}

	//for (auto i = 0; i < N; i++, pa++) {
	//	scanf("%s %d %d %f", pa->name, &pa->year, &pa->part, &pa->studynum);
	//}
	//fwrite(a, size, N, fp);
	//rewind(fp);
	fread(b, size, N, fp);
	for (auto i = 0; i < N; i++, pb++) {
		printf("%s  %d  %d  %f\n", pb->name, pb->year, pb->part, pb->studynum);
	}
	fclose(fp);
	return 0;
}