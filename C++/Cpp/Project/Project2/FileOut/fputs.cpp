/*
// ������ļ�
// ����ԭ�� int fputs( char *str, FILE *fp );

#include <iostream>
using namespace std;

int main() {
	FILE* fp;
	if ((fp = fopen("1.txt", "at+")) == NULL) {
		cout << "�ļ���ʧ�ܣ�������";
	}

	const char* str = "www.baidu.com\n";
	for (auto i = 1; i <= 10; i++)
		fputs(str, fp);
	fclose(fp);
}*/