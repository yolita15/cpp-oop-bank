#include "stdafx.h"
#include "Bank.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include <iostream>

void printMenu()
{
	std::cout << "*** BANK MENU ***" << std::endl;
	std::cout << std::endl;
	std::cout << "1   List costumers" << std::endl;
	std::cout << "2   Add new customer" << std::endl;
	std::cout << "3   Delete customer" << std::endl;
	std::cout << "4   List all accounts" << std::endl;
	std::cout << "5   List customer accounts" << std::endl;
	std::cout << "6   Add new account" << std::endl;
	std::cout << "7   Delete account" << std::endl;
	std::cout << "8   Withdraw from account" << std::endl;
	std::cout << "9   Deposit to account" << std::endl;
	std::cout << "10  Transfer" << std::endl;
	std::cout << "11  Display info for the bank" << std::endl;
	std::cout << "12  Quit" << std::endl;
	std::cout << std::endl;
}

int main()
{

	Bank bank("Barclays Bank", "39 High St, Sutton SM1 1DR, Britain"); 
	
	printMenu();

	int choice;
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	while (true)
	{
		if (choice == 1)
		{
			std::cout << "*** List customers ***" << std::endl;
			std::cout << std::endl;

			bank.listCustomers();
			std::cout << std::endl;

		}
		else if (choice == 2)
		{
			std::cout << "*** Add new customer ***" << std::endl;
			std::cout << std::endl;

			std::string id;
			std::cout << "Enter customer ID: ";
			std::cin >> id;
			
			std::string name;
			std::cout << "Enter customer name: ";
			std::cin.ignore();
			std::getline(std::cin, name);
			

			std::string address;
			std::cout << "Enter customer address: ";
			std::cin >> address;

			bank.addCustomer(id, name, address);
			std::getline(std::cin, address);
			
		}
		else if (choice == 3)
		{
			std::cout << "*** Delete customer ***" << std::endl;
			std::cout << std::endl;

			std::string id;
			std::cout << "Enter customer ID: ";
			std::cin >> id;

			bank.deleteCustomer(id);
			std::cout << std::endl;
		}
		else if (choice == 4)
		{
			std::cout << "*** List all accounts ***" << std::endl;
			std::cout << std::endl;

			bank.listAccounts();
			std::cout << std::endl;
		}
		else if (choice == 5)
		{
			std::cout << "*** List customer account ***" << std::endl; 
			std::cout << std::endl;

			std::string id;

			if (bank.haveAccounts())
			{				
				std::cout << "Enter customer ID: ";
				std::cin >> id;
			}

			bank.listCustomerAccount(id);
			std::cout << std::endl;
		}
		else if (choice == 6)
		{
			std::cout << "*** Add new account ***" << std::endl;
			std::cout << std::endl;

			char choiceOfType;
			std::cout << "Choose type of account" << std::endl;
			std::cout << std::endl;
			std::cout << "A   Current" << std::endl;
			std::cout << "B   Savings" << std::endl;
			std::cout << "C   Privilege" << std::endl;
			std::cout << std::endl;
			std::cout << "Choice: ";
			std::cin >> choiceOfType;
			
			std::string iban;
			std::cout << "Enter IBAN: ";
			std::cin >> iban;
			
			std::string id;
			std::cout << "Enter customer ID: ";
			std::cin >> id;
			
			double amount;
			std::cout << "Enter amount: ";
			std::cin >> amount;
			
			if (choiceOfType == 'A')
			{
				bank.addAccount(current, iban, id, amount);
				std::cout << std::endl;
			}
			else if (choiceOfType == 'B')
			{
				bank.addAccount(savings, iban, id, amount);
				std::cout << std::endl;
			}
			else if (choiceOfType == 'C')
			{
				bank.addAccount(privilege, iban, id, amount);
				std::cout << std::endl;
			}
			else 
			{
				std::cout << "Wrong choice of account type!" << std::endl;
			}
		}
		else if (choice == 7)
		{
			std::cout << "*** Delete account ***" << std::endl;
			std::cout << std::endl;

			std::string iban;
			std::cout << "Enter IBAN: ";
			std::cin >> iban;

			bank.deleteAccount(iban);
			std::cout << std::endl;
		}
		else if (choice == 8)
		{
			std::cout << "*** Withdraw from account ***" << std::endl;
			std::cout << std::endl;

			std::string iban;
			std::cout << "Enter IBAN: ";
			std::cin >> iban;

			double amount;
			std::cout << "Enter amount: ";
			std::cin >> amount;

			bank.withdrawFrom(iban, amount);
			std::cout << std::endl;
		}
		else if (choice == 9)
		{
			std::cout << "*** Deposit to account ***" << std::endl;
			std::cout << std::endl;

			std::string iban;
			std::cout << "Enter IBAN: ";
			std::cin >> iban;

			double amount;
			std::cout << "Enter amount: ";
			std::cin >> amount;

			bank.depositTo(iban, amount);
			std::cout << std::endl;
		}
		else if (choice == 10)
		{
			std::cout << "*** Transfer ***" << std::endl;
			std::cout << std::endl;

			std::string fromIban;
			std::cout << "Enter account IBAN you want to transef from: ";
			std::cin >> fromIban;

			std::string toIban;
			std::cout << "Enter account IBAN you want to transef to: ";
			std::cin >> toIban;

			double amount;
			std::cout << "Enter the amount you want to transfer: ";
			std::cin >> amount;

			bank.transfer(fromIban, toIban, amount);
			std::cout << std::endl;
		}
		else if (choice == 11)
		{
			std::cout << "*** Display info for the bank ***" << std::endl;
			std::cout << std::endl;

			bank.display();
			std::cout << std::endl;
		}
		else if (choice == 12)
		{
			std::cout << "*** Goodbye! ***" << std::endl;

			return 0;
		}
		else
		{
			std::cout << "Wrong input!";
			std::cout << std::endl;
		}

		system("pause");		
		system("cls");
		printMenu();

		std::cout << "Enter your choice: ";
		std::cin >> choice;
	}
	
    return 0;
}

