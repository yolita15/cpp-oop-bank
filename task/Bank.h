#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Account.h"

enum accountTypes { current, savings, privilege };

class Bank
{
public:
	Bank() {};
	Bank(const std::string, const std::string);
	~Bank();

	std::string getName() const;
	std::string getAddress() const;

	void addCustomer(const std::string, const std::string, const std::string);
	void listCustomers() const;
	void deleteCustomer(const std::string);

	void addAccount(const accountTypes, const std::string, const std::string, const double);
	void listAccounts() const;
	void deleteAccount(const std::string);

	void listCustomerAccount(const std::string);
	bool haveAccounts() const;

	void depositTo(const std::string, const double);
	void withdrawFrom(const std::string, const double);
	void transfer(const std::string, const std::string, const double);
	void display() const;

private:
	std::string name;
	std::string address;
	std::vector<Customer> customers;
	std::vector<Account*> accounts;
};

