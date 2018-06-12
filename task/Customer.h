#pragma once
#include <string>


class Customer
{
public:
	Customer() {};
	Customer(const std::string, const std::string, const std::string);
	Customer(const Customer&);
	Customer& operator=(const Customer&);
	~Customer() {};

	std::string getId() const;
	std::string getName() const;
	std::string getAddress() const;

	void display() const;
	
private:
	std::string id;
	std::string name;
	std::string address;

	void copyData(const Customer&);
};

