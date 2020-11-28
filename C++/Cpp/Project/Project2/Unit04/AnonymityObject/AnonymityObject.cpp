#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Account {
	double balance;
public:
	Account() {
		balance = 0;   // ¥Ê»Î”‡∂Ó
	}
	Account(double balance_) {
		balance = balance_;
	}
	void deposit(double amount) {
		balance += amount;    // ’Àªß”‡∂Ó
	}
	double withdraw(double amount) {   // »°«Æ
		auto temp{ 0.0 };
		if (balance < amount) {
			temp = balance;
			balance = 0;
			return temp;
		}
		else {
			balance -= amount;
			return amount;
			cin.swap();
		}
	}
};

int main() {
	Account a1;
	Account a2 = Account(100.0);

	a1.deposit(9.0);
	cin.

		cout << a1.withdraw(10.0) << endl;
	cout << a2.withdraw(52.00) << endl;
	cout << Account(1000.0).withdraw(1000.1) << endl;

	return 0;