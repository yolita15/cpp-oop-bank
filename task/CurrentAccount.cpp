#include "stdafx.h"
#include "CurrentAccount.h"
#include <iostream>

CurrentAccount::CurrentAccount() : Account() {}

CurrentAccount::CurrentAccount(const std::string iban, const std::string ownerId, const double amount) :
	Account(iban, ownerId, amount) {}

CurrentAccount::CurrentAccount(const CurrentAccount& other) : Account(other) {}

CurrentAccount& CurrentAccount::operator=(const CurrentAccount& other)
{
	if (this != &other)
	{
		Account::operator=(other);
	}

	return *this;
}

void CurrentAccount::deposit(const double amount)
{
	addAmount(amount);
}

bool CurrentAccount::withdraw(const double amount)
{
	double currentAmount = getBalance();
	if (currentAmount < amount)
	{
		return false;
	}
	else
	{
		removeAmount(amount);
		return true;
	}
}

void CurrentAccount::display() const
{
	std::cout << std::endl;
	std::cout << "Type of the account: Current Account" << std::endl;
	std::cout << "IBAN: " << getIban() << std::endl;
	std::cout << "Owner ID: " << getOwnerId() << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
	std::cout << std::endl;
}



