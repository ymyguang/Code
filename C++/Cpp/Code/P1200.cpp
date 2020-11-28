#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long sum_1 = 1,sum_2 = 1,num;
bool f = 0;

int main()
{
	char str1[100],str2[100];
	cin >> str1 >> str2;
	if (strlen(str1) < strlen(str2))  f = 1;
	for (int i = 0;i < strlen(str1);i++){
		num = str1[i] - 'A' + 1 ;
		sum_1 = sum_1 * num;
		if(i < strlen(str2)){
			num = str2[i] - 'A' + 1;
			sum_2 = sum_2 * num; 
		}
	}
	if (f){
		for (int j = strlen(str1); j < strlen(str2);j++){
			num = str2[j] - 'A' + 1;
			sum_2 = sum_2 * num; 
		}
	}	
	if (sum_2%47== sum_1%47) cout << "GO";
	else cout << "STAY";
	return 0;
 } 
