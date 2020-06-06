#include "Group.h"

Group::Group()
{
	this->group_id = 0;
	this->group_payer = new Payer();
	this->type = "group";
	this->groupMembers = 0;
}

Group::Group(const size_t group_id, Payer* group_payer)
{
	this->group_id = group_id;
	this->group_payer = group_payer;
	this->type = "group";
	this->institution_id++;
}

Group* Group::clone()
{
	return new Group(*this);
}

size_t Group::getGroupID() const
{
	return this->group_id;
}

bool Group::has_member(const Person& user) const
{
	if (user.getInsuranceID() != 0) {
		std::function<bool(const Person&, const Group&)> rule = this->group_payer->getMatchRule();

		return rule(user, *this);
	}

	return false;
}

Payer* Group::payer()
{
	return group_payer;
}

void Group::checkMembership(const Person& user) {
	std::function<bool(const Person&, const Group&)> rule = this->group_payer->getMatchRule();
	if (this->has_member(user)) { this->groupMembers++; };
}

bool Group::valid()
{
	String groupPayerName = this->payer()->getPayerName();
	return !(strcmp(groupPayerName.c_str(), "") == 0);
}


size_t Group::getMembers() const
{
	return this->groupMembers;
}

void Group::print() {
	std::cout << "Group ID: " << group_id << std::endl;
	group_payer->print();
	std::cout << "Group members: " << groupMembers << std::endl;
}
