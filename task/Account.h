#pragma once
#include <string>

class Account
{
public:
	Account();
	Account(const std::string, const std::string, const double);
	Account(const Account&);
	Account& operator=(const Account&);
	~Account() {};

	std::string getIban() const;
	std::string getOwnerId() const;
	double getBalance() const;

	virtual void deposit(const double) = 0;
	virtual bool withdraw(const double) = 0;
	virtual void display() const = 0;

protected:
	void addAmount(const double);
	void removeAmount(const double);

private:
	std::string iban;
	std::string ownerId;
	double amount;
	
	void copyData(const Account&);
};

