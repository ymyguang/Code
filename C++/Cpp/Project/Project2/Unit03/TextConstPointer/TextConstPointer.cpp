#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	//��������
	const int x = 43;
	//�������ɱ�
	//x = 32; ��x��: ���ܸ�������ֵ

	//  ����ָ����ָ�����ݲ��ɱ�
	int y = 2;
	const int* p = &x;
	//  (*p) = 22; ��p��: ���ܸ�������ֵ
	const int* q = &y;
	//  (*q) = 5;

	//  ָ�볣�����ɱ�
	int* const r = &y;
	int z = 3;
	(*r) = 20;
	cout << *r << " " << y << endl;
	//  ��ָ�볣��
	const int* const s = &y;
	//  char*

	int zx = 0, * const px = &zx;
	cout << zx << endl;
	*px = 21;
	cout << zx;

	return 0;
}