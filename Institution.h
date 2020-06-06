#pragma once
#include "String.h"
#include "Person.h"
#include "Payer.h"

class Institution {
private:
	String institution_name;
protected:
	String type;
public:
	static size_t institution_id;

	virtual Institution* clone() = 0;

	virtual bool has_member(const Person& user) const = 0;
	virtual Payer* payer() = 0;
	virtual bool valid() = 0;
	virtual size_t getMembers() const = 0;
	
	virtual void checkMembership(const Person& user) = 0;

	void setInstitutionID(const size_t id) { this->institution_id = id; };
	const size_t getInstitutionID() const { return this->institution_id; };
	const String& getType() const { return this->type; };
	virtual void print() = 0;
};