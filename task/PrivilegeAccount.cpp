#include "stdafx.h"
#include "PrivilegeAccount.h"
#include <iostream>

PrivilegeAccount::PrivilegeAccount() :
	Account(),
	overdraft(0) {}

PrivilegeAccount::PrivilegeAccount(const std::string iban, const std::string ownerId, const double amount, const double overdraft) :
	Account(iban, ownerId, amount),
	overdraft(overdraft) {}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount& other) :
	Account(other),
	overdraft(other.overdraft) {}

PrivilegeAccount& PrivilegeAccount::operator=(const PrivilegeAccount& other)
{
	if (this != &other)
	{
		Account::operator=(other);
		overdraft = other.overdraft;
	}

	return *this;
}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}


void PrivilegeAccount::deposit(const double amount)
{
	addAmount(amount);
}

bool PrivilegeAccount::withdraw(const double amount)
{
	double currentAllowedAmount = getBalance() + overdraft;
	if (currentAllowedAmount < amount)
	{
		return false;
	}
	else
	{
		removeAmount(amount);
		return true;
	}
}

void PrivilegeAccount::display() const
{
	std::cout << std::endl;
	std::cout << "Type of the account: Privilege Account" << std::endl;
	std::cout << "IBAN: " << getIban() << std::endl;
	std::cout << "Owner ID: " << getOwnerId() << std::endl;
	std::cout << "Allowed overdraft: " << getOverdraft() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
	std::cout << std::endl;
}
