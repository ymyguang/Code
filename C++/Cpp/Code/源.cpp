#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <stdio.h>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

/* ����ȡ�ô�����Ϣ */
DWORD g_dwErr;

/* ��������Ĵ�С */
const int MAX_SIZE = 40960;

/*
		�˽ṹ�����ڱ���������Ϣ
*/
typedef struct stWeatherInfo
{
	string date;        //����
	string wea;                //����
	string tem;                //�¶�
	string win;                //����
}WeatherInfo, *pWeatherInfo;

/* ���ڴ���THML�е����ݣ�����Ӧ��Ϣ����ṹ���� */
void GetWeather(const string& s);

int main()
{
	/* ��ʼ�� */
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	const char* hostname = "www.weather.com.cn";
	struct hostent* host = gethostbyname(hostname);

	/* ��ʼ��һ�����ӷ������Ľṹ�� */
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(80);

	/* �˴�Ҳ���Բ�����ô��������Ҫ��gethostbyname������ַpingһ�£��ó�IPҲ�ǿ��Ե� */
	serveraddr.sin_addr.S_un.S_addr = *((int*)*host->h_addr_list);

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		cout << "socket error" << endl;
		return -1;
	}
	cout << "socket succeed" << endl;

	if (connect(sock, (struct sockaddr*)&serveraddr, sizeof(sockaddr_in)) == -1) {
		g_dwErr = GetLastError();
		cout << "connect error" << endl;
		closesocket(sock);
		return -1;
	}
	cout << "connect succeed" << endl;

	/* GET���� */
	const char* bufSned = "GET http://www.weather.com.cn/weather/101280601.shtml\r\n";

	/* ����GET���� */
	if (send(sock, bufSned, strlen(bufSned), 0) > 0) {
		cout << "send succeed" << endl;
	}
	else {
		g_dwErr = GetLastError();
		cout << "send error, �����ţ� " << g_dwErr << endl;
		closesocket(sock);
		return -1;
	}

	/* �ļ������ڰ�HTMLԴ�뱣��������ûʲô�ô���ֻ��Ϊ���Լ���һ��Դ����� */
	FILE *fp;
	fp = fopen("E:/get.txt", "w");

	char BufRecv[MAX_SIZE] = {};
	int nLen = 0;
	string HtmlData;

	/* ��ʼ�������� */
	while ((nLen = recv(sock, BufRecv, MAX_SIZE, 0)) > 0) {

		/* д�ļ� */
		fwrite(BufRecv, 1, nLen, fp);

		/* ������ƴ�ӳ�string���ͣ���������Ĵ��� */
		HtmlData += BufRecv;
	}

	/* ��ʼ����HTML */
	string Area0 = "<ul class=\"t clearfix\">";
	string Area1 = "<li class=\'on\'>";
	string Area2 = "</li>";

	string::size_type PosBegin0;
	string::size_type PosBegin;
	string::size_type PosEnd;
	string s;
	PosBegin0 = HtmlData.find(Area0);
	if (PosBegin0 > 0) {
		PosBegin = HtmlData.find(Area1, PosBegin0);
		PosEnd = HtmlData.find(Area2, PosBegin);
		s = HtmlData.substr(PosBegin, PosEnd - PosBegin + 5);
		//cout << s << endl;                //s��Ϊ�洢������Ϣ��HTMLԴ��
	}
	/* ����HTML���� */

	/* ����洢���������ֵ�HTML���� */
	GetWeather(s);

	fclose(fp);
	cin.get();
	closesocket(sock);
	return 0;
}

void GetWeather(const string& s)
{
	WeatherInfo weatherinfo;
	string::size_type DataPosBegin = s.find("<h1>");
	string::size_type DataPosEnd = s.find("</h1>");
	weatherinfo.date = s.substr(DataPosBegin + 4, DataPosEnd - DataPosBegin - 4);

	string::size_type WeaPosEnd = s.find("</p>");
	string::size_type WeaPosBegin = s.rfind(">", WeaPosEnd);
	weatherinfo.wea = s.substr(WeaPosBegin + 1, WeaPosEnd - WeaPosBegin - 1);

	string::size_type TemPosBegin1 = s.find("<span>");
	string::size_type TemPosEnd1 = s.find("</span>");
	string tem1 = s.substr(TemPosBegin1 + 6, TemPosEnd1 - TemPosBegin1 - 6);

	string::size_type TemPosBegin2 = s.find("<i>");
	string::size_type TemPosEnd2 = s.find("</i>", TemPosBegin2);
	string tem2 = s.substr(TemPosBegin2 + 3, TemPosEnd2 - TemPosBegin2 - 3);
	weatherinfo.tem = tem1 + "/" + tem2;

	string::size_type WinPosBegin = s.find("</em>");
	WinPosBegin = s.find("<i>", WinPosBegin);
	string::size_type WinPosEnd = s.find("</i>", WinPosBegin);
	weatherinfo.win = s.substr(WinPosBegin + 3, WinPosEnd - WinPosBegin - 3);

	/*
	cout << "���ڣ�" << weatherinfo.date << endl;
	cout << "������" << weatherinfo.wea << endl;
	cout << "�¶ȣ�" << weatherinfo.tem << endl;
	cout << "������" << weatherinfo.win << endl;
	*/

	/* �ѻ�ȡ��������Ϣд�뵽�ļ��� */
	FILE *fp;
	fp = fopen("E:/weather.txt", "w");
	fwrite(weatherinfo.date.c_str(), 1, weatherinfo.date.length(), fp);
	fwrite(weatherinfo.wea.c_str(), 1, weatherinfo.wea.length(), fp);
	fwrite(weatherinfo.tem.c_str(), 1, weatherinfo.tem.length(), fp);
	fwrite(weatherinfo.win.c_str(), 1, weatherinfo.win.length(), fp);

	fclose(fp);
}