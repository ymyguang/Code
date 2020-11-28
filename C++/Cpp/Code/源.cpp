#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <stdio.h>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

/* 用于取得错误信息 */
DWORD g_dwErr;

/* 保存数组的大小 */
const int MAX_SIZE = 40960;

/*
		此结构体用于保存天气信息
*/
typedef struct stWeatherInfo
{
	string date;        //日期
	string wea;                //天气
	string tem;                //温度
	string win;                //风力
}WeatherInfo, *pWeatherInfo;

/* 用于处理THML中的数据，把相应信息放入结构体中 */
void GetWeather(const string& s);

int main()
{
	/* 初始化 */
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	const char* hostname = "www.weather.com.cn";
	struct hostent* host = gethostbyname(hostname);

	/* 初始化一个连接服务器的结构体 */
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(80);

	/* 此处也可以不用这么做，不需要用gethostbyname，把网址ping一下，得出IP也是可以的 */
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

	/* GET请求 */
	const char* bufSned = "GET http://www.weather.com.cn/weather/101280601.shtml\r\n";

	/* 发送GET请求 */
	if (send(sock, bufSned, strlen(bufSned), 0) > 0) {
		cout << "send succeed" << endl;
	}
	else {
		g_dwErr = GetLastError();
		cout << "send error, 错误编号： " << g_dwErr << endl;
		closesocket(sock);
		return -1;
	}

	/* 文件，用于把HTML源码保存起来，没什么用处，只是为了自己看一下源码而已 */
	FILE *fp;
	fp = fopen("E:/get.txt", "w");

	char BufRecv[MAX_SIZE] = {};
	int nLen = 0;
	string HtmlData;

	/* 开始接收数据 */
	while ((nLen = recv(sock, BufRecv, MAX_SIZE, 0)) > 0) {

		/* 写文件 */
		fwrite(BufRecv, 1, nLen, fp);

		/* 把数组拼接成string类型，方便下面的处理 */
		HtmlData += BufRecv;
	}

	/* 开始分析HTML */
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
		//cout << s << endl;                //s即为存储天气信息的HTML源码
	}
	/* 结束HTML分析 */

	/* 处理存储有天气部分的HTML代码 */
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
	cout << "日期：" << weatherinfo.date << endl;
	cout << "天气：" << weatherinfo.wea << endl;
	cout << "温度：" << weatherinfo.tem << endl;
	cout << "风力：" << weatherinfo.win << endl;
	*/

	/* 把获取的天气信息写入到文件中 */
	FILE *fp;
	fp = fopen("E:/weather.txt", "w");
	fwrite(weatherinfo.date.c_str(), 1, weatherinfo.date.length(), fp);
	fwrite(weatherinfo.wea.c_str(), 1, weatherinfo.wea.length(), fp);
	fwrite(weatherinfo.tem.c_str(), 1, weatherinfo.tem.length(), fp);
	fwrite(weatherinfo.win.c_str(), 1, weatherinfo.win.length(), fp);

	fclose(fp);
}