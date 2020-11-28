#include <iostream>
#include <iomanip>
using namespace std; 
int main()
{
	for (char letter = 'a';letter <= 'z';letter = letter+1)
		cout << setw(3) << letter;
		cout <<endl;
		return 0;
}
