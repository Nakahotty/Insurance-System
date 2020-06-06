#pragma once
#include "Vector.h"
#include "Institution.h"

class Organization : public Institution {
protected:
	Vector<Institution*> institution_list;
	String organization_address;

	Institution* main_institution;  // това го няма в условието
public:
	Organization();
	Organization(const Vector<Institution*> institution_list, const String& adress);
	Organization* clone();
	Vector<Institution*>& getInstitutionList();
	const String& getOrganizationAdress() const;

	bool has_member(const Person& user) const;
	Payer* payer();
	bool valid();

	void checkMembership(const Person& user);
	void checkMainInstitution(Institution* inst);

	size_t getMembers() const;
	void add_institution(Institution* inst);
	void print();
};