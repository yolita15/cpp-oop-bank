#pragma once
#include "Account.h"
class CurrentAccount :
	public Account
{
public:
	CurrentAccount();
	CurrentAccount(const std::string, const std::string, const double);
	CurrentAccount(const CurrentAccount&);
	CurrentAccount& operator=(const CurrentAccount&);
	~CurrentAccount() = default;

	void deposit(const double) override;
	bool withdraw(const double) override;
	virtual void display() const override;

};

