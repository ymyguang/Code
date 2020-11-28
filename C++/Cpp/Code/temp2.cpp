#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int temp[101];
	for (int i = 1;i <= 100;i++)
	  cin >> temp[i];
	sort (temp+1,temp+1+100);
	for (int j = 1; j <=100; j++)
		cout << temp[j] <<" ";
	return 0;
}
