#include "stdafx.h"
#include "Account.h"


Account::Account() :
	iban(),
	ownerId(),
	amount(0) {}

Account::Account(const std::string iban, const std::string ownerId, const double amount) :
	iban(iban),
	ownerId(ownerId),
	amount(amount) {}

Account::Account(const Account& other)
{
	copyData(other);
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		copyData(other);
	}

	return *this;
}

std::string Account::getIban() const
{
	return iban;
}

std::string Account::getOwnerId() const
{
	return ownerId;
}


void Account::addAmount(const double amount)
{
	this->amount += amount;
}

void Account::removeAmount(const double amount)
{
	this->amount -= amount;
}

double Account::getBalance() const
{
	return amount;
}

void Account::copyData(const Account& other)
{
	iban = other.iban;
	ownerId = other.ownerId;
	amount = other.amount;
}
