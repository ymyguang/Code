// �����ļ������ݿ飨�ֽ����ݣ�
//����ԭ�ͣ�size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );
//*ptr ����Ҫ���в�������ַ���
//size_t size һ�����ݰ��Ĵ�С
//size_t count ���ݰ��ĸ���
//FILE *fp �������ļ�
#include <iostream>
using namespace std;
#define N 100
int main() {
	FILE* fp;
	int a[N], b[N];
	int size = sizeof(int);
	if ((fp = fopen("out", "rb+")) == NULL) { //������д���ȡ�ļ����ı��༭���޷��鿴
		cout << "��ȡʧ��";
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