#include <iostream>
#include <string>

class BankAccount {
private:
	std::string owner;
	double balance;

public:

	void setOwner(const std::string& ownerName) 
    {
		owner = ownerName;
	}
    std::string getOwner() const
    {
		return owner;
	}
    void deposit(double amount) 
    {
		if (amount > 0.0) {
			balance += amount;
		} 
	}

    void withdraw(double amount) {
		if (amount <= 0.0) {
			std::cout << "Withdrawal failed, because amount must be > 0.\n";
			return;
		}

		if (amount <= balance) {
			balance -= amount;
		} else {
			std::cout << "Withdrawal failed, beacuse insufficient funds.\n";
		}
	}
	double getBalance() const;
	std::string getAccountInfo() const;
};

double BankAccount::getBalance() const {
	return balance;
}

std::string BankAccount::getAccountInfo() const {
	return "Owner: " + owner + ", Balance: " + std::to_string(balance);
}


//////////////////////////////MAIN/////////////////////////////
int main() {
	BankAccount account;

	account.setOwner("Marc Born");
	account.deposit(107326.0);
	account.withdraw(250.0);
	account.withdraw(1000.0);
	account.deposit(20.0);

	std::cout << "Owner: " << account.getOwner() << "\n";
	std::cout << "Balance: " << account.getBalance() << "\n";
	std::cout << account.getAccountInfo() << "\n";

	return 0;
}
//////////////////////////////MAIN/////////////////////////////