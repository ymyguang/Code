#include<iostream>
#include<conio.h>
#include<windows.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�ģ����Ǳ�������

using namespace std;

int main() {
	char a;
	int now = 0; // ���ֵ����ģ�⺯���ж��û�״̬���Ӷ�ִ�ж�Ӧ����
	printf("��Q��ʼ������\n");
	printf("��W��ʼ�Ҽ����\n");
	printf("���ո�ֹͣ���\n");
	while (1) {
		if (KEY_DOWN(VK_SPACE)) {//VK_SPACE �ǿո�������ֵ
			now = 0;
			Sleep(100);//û�д�������ɣ����¼�ִ�У���������ģ�⣬�ɿ����̲ſ�ʼִ�У�ʵ�����ǣ����¾�ִ�У�
		}
		if (KEY_DOWN('Q')) {
			now = 1;
			Sleep(100);
		}
		if (KEY_DOWN('W')) {
			now = 2;
			Sleep(100);
		}
		if (now == 1) {//ģ�������
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(1);//Ҫ����ĳЩӦ�õķ�Ӧʱ��
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (now == 2) {//ģ�����Ҽ�
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}

		Sleep(2);//������ ��λ�Ǻ���
	}
}