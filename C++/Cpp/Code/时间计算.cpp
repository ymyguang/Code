#include <iostream>
#include <string.h>
using namespace std;

int fst[3],sen[3];
int jisuan (string str,int n)
{
	int len = str.length();
	if (len == 4)
	{
		fst[n] = (str[2] - '0')*10 + (str[3] - '0');
		sen[n] = (str[0] - '0')*10 + (str[1] - '0');
	}
	else 
	{
		fst[n] = (str[1] - '0')*10 + (str[2] - '0');    //���� 
		sen[n] = (str[0] - '0');                        //Сʱ 
	}
}
int main()
{
	string tim1,tim2;
	cin >> tim1 >> tim2;
	jisuan(tim1,1);  //����ʱ�� 
	jisuan(tim2,2);  //����ʱ�� 
	if (fst[2] < fst[1])
	{
		fst[2] = fst[2] + 60;
		sen[2]--; 	
	} 
	int hour = sen[2] - sen[1]; 
	int minc = fst[2] - fst[1]; 
	cout << hour <<" hrs " << minc << " mins";
	return 0;
 } 
