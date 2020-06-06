#pragma once
#include "String.h"

class Person {
private:
	String name;
	size_t insurance_id;
public:
	Person();
	Person(const String& name, const size_t insurance_id);
	Person(const String& name);
	const String& getName() const;
	size_t getInsuranceID() const;

	void print();
};