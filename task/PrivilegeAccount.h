#pragma once
#include "Account.h"
class PrivilegeAccount :
	public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const std::string, const std::string, const double, const double);
	PrivilegeAccount(const PrivilegeAccount&);
	PrivilegeAccount& operator=(const PrivilegeAccount&);
	~PrivilegeAccount() = default;

	double getOverdraft() const;

	void deposit(const double) override;
	bool withdraw(const double) override;
	virtual void display() const override;

private:
	double overdraft;
};

