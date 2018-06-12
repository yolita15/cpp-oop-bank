#pragma once
#include "Account.h"
class SavingsAccount :
	public Account
{
public:
	SavingsAccount();
	SavingsAccount(const std::string, const std::string, const double, const double);
	SavingsAccount(const SavingsAccount&);
	SavingsAccount& operator=(const SavingsAccount&);
	~SavingsAccount() = default;

	double getInterestRate() const;
	void deposit(const double) override;
	bool withdraw(const double) override;
	virtual void display() const override;

private:
	double interestRate;
};

