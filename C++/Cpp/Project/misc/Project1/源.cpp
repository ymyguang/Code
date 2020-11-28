#include<iostream>
#include<conio.h>
#include<windows.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的

using namespace std;

int main() {
	char a;
	int now = 0; // 标记值，供模拟函数判断用户状态，从而执行对应艚子
	printf("按Q开始左键点击\n");
	printf("按W开始右键点击\n");
	printf("按空格停止点击\n");
	while (1) {
		if (KEY_DOWN(VK_SPACE)) {//VK_SPACE 是空格的虚拟键值
			now = 0;
			Sleep(100);//没有此语句会造成：按下即执行，这里的语句模拟，松开键盘才开始执行（实际上是：按下就执行）
		}
		if (KEY_DOWN('Q')) {
			now = 1;
			Sleep(100);
		}
		if (KEY_DOWN('W')) {
			now = 2;
			Sleep(100);
		}
		if (now == 1) {//模拟点击左键
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(1);//要留给某些应用的反应时间
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (now == 2) {//模拟点击右键
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(10);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}

		Sleep(2);//点击间隔 单位是毫秒
	}
}