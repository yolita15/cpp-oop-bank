#include "stdafx.h"
#include "Bank.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include <iostream>

Bank::Bank(const std::string name, const std::string address) :
	name(name),
	address(address) {}


std::string Bank::getName() const
{
	return name;
}

std::string Bank::getAddress() const
{
	return address;
}

void Bank::addCustomer(const std::string id, const std::string name, const std::string address)
{
	if (!customers.empty())
	{
		for (int i = 0; i < customers.size(); i++)
		{
			if (customers[i].getId() == id)
			{
				std::cout << "Customer with that ID already exists!" << std::endl;
				return;
			}
		}
	}

	Customer customer(id, name, address);
	customers.push_back(customer);
	std::cout << "Successfully added new customer!" << std::endl;
}

void Bank::listCustomers() const
{
	if (!customers.empty())
	{
		for (int i = 0; i < customers.size(); i++)
		{
			customers[i].display();
		}
	}
	else
	{
		std::cout << "There are no customers of the bank!" << std::endl;
	}
	
}

void Bank::deleteCustomer(const std::string id)
{
	
	if (!customers.empty())
	{
		bool notFound = true;
		for (int i = 0; i < customers.size(); i++)
		{
			if (customers[i].getId() == id)
			{
				customers.erase(customers.begin() + i);
				std::cout << "Successfully deleted customer with ID: " << id << std::endl;
				notFound = false;
				break;
			}
		}
		
		if (notFound)
		{
			std::cout << "Customer not found!" << std::endl; 
		}
	}
	else
	{
		std::cout << "There are no customers of the bank!" << std::endl;
	}

	if (!accounts.empty())
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getOwnerId() == id)
			{
				delete accounts[i];
				accounts.erase(accounts.begin() + i);
				--i;
			}
		}
	}
}

void Bank::addAccount(const accountTypes accountType, const std::string iban, const std::string ownerId, const double amount)
{

	if (!accounts.empty())
	{
		bool flag = false;
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == iban)
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			std::cout << "Error! IBAN already exists!" << std::endl;
			return;
		}
	}

	if (!customers.empty())
	{
		bool notFound = true;
		for (int i = 0; i < customers.size(); i++)
		{
			if (customers[i].getId() == ownerId)
			{
				if (accountType == current)
				{
					CurrentAccount *account = new CurrentAccount(iban, ownerId, amount);
					accounts.push_back(account);

					std::cout << "Successfully added new current account!" << std::endl;
					notFound = false;

					break;
				}
				if (accountType == savings)
				{
					double interestRate;
					std::cout << "Account type 'savings' must have interest rate. Enter interest rate: ";
					std::cin >> interestRate;

					SavingsAccount *account = new SavingsAccount(iban, ownerId, amount, interestRate);
					accounts.push_back(account);

					std::cout << "Successfully added new savings account!" << std::endl;
					notFound = false;

					break;
				}
				if (accountType == privilege)
				{
					double overdraft;
					std::cout << "Account type 'privilege' must have overdraft. Enter overdraft: ";
					std::cin >> overdraft;

					PrivilegeAccount *account = new PrivilegeAccount(iban, ownerId, amount, overdraft);
					accounts.push_back(account);

					std::cout << "Successfully added new privilege account!" << std::endl;
					notFound = false;

					break;
				}
				else
				{
					std::cout << "Wrong type of account!" << std::endl;
				}
			}
		}

		if (notFound)
		{
			std::cout << "Customer not found!" << std::endl;
		}		
	}
	else
	{
		std::cout << "There are no customers of the bank!" << std::endl;
	}
}

void Bank::listAccounts() const
{
	if (!accounts.empty())
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			accounts[i]->display();
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}	
}

void Bank::deleteAccount(const std::string iban)
{
	if (!accounts.empty())
	{
		bool notFound = true;
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == iban)
			{
				delete accounts[i];
				accounts.erase(accounts.begin() + i);
				std::cout << "Successfully deleted account with IBAN: " << iban << std::endl;

				notFound = false;
				break;
			}
		}
		if (notFound)
		{
			std::cout << "IBAN Not found!" << std::endl;
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}
	
}

void Bank::listCustomerAccount(const std::string customerId)
{
	if (!accounts.empty())
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getOwnerId() == customerId)
			{
				accounts[i]->display();
			}
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}
}

bool Bank::haveAccounts() const
{
	if (!accounts.empty()) return true;
	else return false;
}

void Bank::depositTo(const std::string iban, const double amount)
{
	bool notFound = true;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			notFound = false;
			break;
		}
	}

	if (notFound)
	{
		std::cout << "IBAN Not found!" << std::endl;
		return;
	}
	
	if (!accounts.empty())
	{
		bool flag = false;
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == iban)
			{
				accounts[i]->deposit(amount);
				std::cout << "Successful deposit to account with IBAN: " << iban << std::endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			std::cout << "Unsuccessful deposit!" << iban << std::endl;
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}
}

void Bank::withdrawFrom(const std::string iban, const double amount)
{
	bool notFound = true;
	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			notFound = false;
			break;
		}
	}

	if (notFound)
	{
		std::cout << "IBAN Not found!" << std::endl;
		return;
	}
	
	if (!accounts.empty())
	{
		bool flag = false;
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == iban)
			{
				flag = accounts[i]->withdraw(amount);
				break;
			}
		}
		
		if (flag)
		{
			std::cout << "Successful withdraw from account with IBAN: " << iban << std::endl;
		}
		else
		{
			std::cout << "Unsuccessful withdraw!" << std::endl;
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}
}

void Bank::transfer(const std::string fromIBAN, const std::string toIBAN, const double amount)
{
	bool flag = false;
	bool transfered = false;

	if (!accounts.empty())
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == fromIBAN)
			{
				flag = accounts[i]->withdraw(amount);
				if (flag) break;
			}
		}

		if (flag == false)
		{
			std::cout << "Impossible transfer!" << std::endl;
			return;
		}

		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i]->getIban() == toIBAN)
			{
				if (flag)
				{
					accounts[i]->deposit(amount);
					transfered = true;
					std::cout << "Successful transfer from account with IBAN " << fromIBAN << " to account with IBAN " << toIBAN << std::endl;
					break;
				}
				
			}
		}
		
		if (transfered == false)
		{
			std::cout << "Unsuccessful transfer!" << std::endl;

			for (int i = 0; i < accounts.size(); i++)
			{
				if (accounts[i]->getIban() == fromIBAN)
				{
					accounts[i]->deposit(amount);
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "No bank accounts in the bank!" << std::endl;
	}
}

void Bank::display() const
{
	std::cout << "Name of the bank: " << getName() << std::endl;
	std::cout << "Address of the bank " << getAddress() << std::endl;
	std::cout << "Number customers of the bank: " << customers.size() << std::endl;
	std::cout << "Number accounts in the bank: " << accounts.size() << std::endl;
}


Bank::~Bank()
{
	if (!accounts.empty())
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			delete accounts[i];
		}
		accounts.clear();
	}
}