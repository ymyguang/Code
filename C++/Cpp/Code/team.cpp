#include<iostream>
#include<stdio.h>
 
using namespace std;
int main(){
	int ss;
	char temp[64];
	ss = 1000;
	sprintf(temp, "%d", ss);
	string s(temp);
	
	//调用string的方法
	cout<<s.c_str()<<endl; //1000
	cout<<s.size()<<endl;  //长度为4 
}
