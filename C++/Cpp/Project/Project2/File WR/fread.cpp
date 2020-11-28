// 读入文件内数据块（字节数据）
//函数原型：size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );
//*ptr 代表要进行操作早的字符串
//size_t size 一个数据包的大小
//size_t count 数据包的个数
//FILE *fp 被操作文件
#include <iostream>
using namespace std;
#define N 100
int main() {
	FILE* fp;
	int a[N], b[N];
	int size = sizeof(int);
	if ((fp = fopen("out", "rb+")) == NULL) { //二进制写入读取文件，文本编辑器无法查看
		cout << "读取失败";
	}
	for (auto i = 1; i <= 5; i++) {
		cin >> a[i];
	}
	fwrite(a, size, N, fp);
	rewind(fp);
	fread(b, size, N, fp);
	fclose(fp);
	for (int i = 1; i <= 5; i++) {
		cout << b[i] << endl;
	}
}