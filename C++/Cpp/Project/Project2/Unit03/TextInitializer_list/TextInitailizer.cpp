//initializer_list�����ã�Ϊ������ݲ���������Ψһ��ͨ��initailizer_list������ʱ���󣬽�����ֵ���ݸ�����
//ʹ�÷�����{}����ʹ�û����ŵ�ʱ��������ͻ��Լ�����һ����ʱ���󣬴��ݸ�������
//2020��4��13��
//By ymyguang
#include <iostream>
void print(std::initializer_list<int> list) {
	//To imitate printf,but this is a bug that only printf simple size valliable;

	for (auto it = list.begin(); it != list.end(); it++) {
		std::cout << *it << " ";
		//The "*" can konw that list add is a per;
	}
	std::cout << std::endl;
}

int main() {
	print({ 1, 2, });
}