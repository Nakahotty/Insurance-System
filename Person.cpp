#include "Person.h"

Person::Person() {
	this->name = "None";
	this->insurance_id = 0;
}

Person::Person(const String& name, const size_t insurance_id)
{
	this->name = name;
	this->insurance_id = insurance_id;
}

Person::Person(const String& name)
{
	this->name = name;
	this->insurance_id = 0;
}

const String& Person::getName() const
{
	return this->name;
}

size_t Person::getInsuranceID() const
{
	return this->insurance_id;
}

void Person::print()
{
	std::cout << "Person name: " << this->name << std::endl;
	std::cout << "Insurance ID: " << this->insurance_id << std::endl;
}
