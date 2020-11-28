/*

// 文件读取
// 函数：char *fgets ( char *str, int n, FILE *fp );
#define N 200
#include <iostream>
using namespace std;
int main() {
	char str[N];
	FILE* fp;
	if ((fp = fopen("out.txt", "r+")) == NULL) {
		cout << "打开文件失败";
	}

	while (fgets(str, N, fp) != NULL) {
		cout << str;
	}
	fclose(fp);
}

*/