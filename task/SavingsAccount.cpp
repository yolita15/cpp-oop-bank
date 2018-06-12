#include "stdafx.h"
#include "SavingsAccount.h"
#include <iostream>


SavingsAccount::SavingsAccount() :
	Account(),
	interestRate(0) {}

SavingsAccount::SavingsAccount(const std::string iban, const std::string  ownerId, const double amount, const double interestRate) :
	Account(iban, ownerId, amount),
	interestRate(interestRate) {}

SavingsAccount::SavingsAccount(const SavingsAccount& other) :
	Account(other),
	interestRate(other.interestRate) {}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other)
{
	if (this != &other)
	{
		Account::operator=(other);
		interestRate = other.interestRate;
	}

	return *this;
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}

void SavingsAccount::deposit(const double amount)
{
	addAmount(amount);
}

bool SavingsAccount::withdraw(const double amount)
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

void SavingsAccount::display() const
{
	std::cout << std::endl;
	std::cout << "Type of the account: Savings Account" << std::endl;
	std::cout << "IBAN: " << getIban() << std::endl;
	std::cout << "Owner ID: " << getOwnerId() << std::endl;
	std::cout << "Annual interest rate: " << getInterestRate() << " %" << std::endl;
	std::cout << "Balance: " << getBalance() << std::endl;
	std::cout << std::endl;
}



