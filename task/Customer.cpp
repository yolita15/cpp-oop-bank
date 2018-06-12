#include "stdafx.h"
#include "Customer.h"
#include <iostream>


Customer::Customer(const std::string id, const std::string name, const std::string address) :
	id(id),
	name(name),
	address(address) {}

Customer::Customer(const Customer& other)
{
	copyData(other);
}

Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		copyData(other);
	}

	return *this;
}

std::string Customer::getId() const
{
	return id;
}

std::string Customer::getName() const
{
	return name;
}

std::string Customer::getAddress() const
{
	return address;
}

void Customer::display() const
{
	std::cout << std::endl;
	std::cout << "ID of the customer: " << getId() << std::endl;
	std::cout << "Name of the customer: " << getName() << std::endl;
	std::cout << "Address of the customer: " << getAddress() << std::endl;
	std::cout << std::endl;
}

void Customer::copyData(const Customer& other)
{
	id = other.id;
	name = other.name;
	address = other.address;
}
