#include <iostream>
using namespace std;

int main() {
	int Max = 0,TimeAns  = 0;
	int n,a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		TimeAns += a;
		if (TimeAns > Max) Max = TimeAns;
		else if (TimeAns < 0) TimeAns = 0;
	}
	cout << Max;
}
