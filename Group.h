#pragma once
#include "Institution.h"

class Group : public Institution {
private:
	size_t group_id;
	Payer* group_payer;
	size_t groupMembers = 0;
public:
	Group();
	Group(const size_t group_id, Payer* group_payer);
	Group* clone();
	size_t getGroupID() const;

	bool has_member(const Person& user) const;
	Payer* payer();
	bool valid();

	void checkMembership(const Person& user);

	size_t getMembers() const;
	void print();
};