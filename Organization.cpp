#include "Organization.h"

Organization::Organization() {
	this->organization_address = "None";
	this->type = "organization";
	this->main_institution = this->institution_list[0];
}

Organization::Organization(const Vector<Institution*> institution_list, const String& adress)
{
	this->institution_list = institution_list;
	this->organization_address = adress;
	this->type = "organization";
	this->main_institution = this->institution_list[0];
	this->institution_id++;
}

Organization* Organization::clone()
{	
	return new Organization(*this);
}

Vector<Institution*>& Organization::getInstitutionList()
{
	return this->institution_list;
}

const String& Organization::getOrganizationAdress() const
{
	return this->organization_address;
}

bool Organization::has_member(const Person& user) const
{
	size_t size = institution_list.getSize();
	for (size_t i = 0; i < size; i++) {
		if (institution_list[i]->has_member(user))
			return true;
	}

	return false;
}

Payer* Organization::payer()
{
	if (this->main_institution != nullptr)
		return this->main_institution->payer();

	return nullptr;
}

bool Organization::valid()
{
	size_t size = this->institution_list.getSize();

	for (size_t i = 0; i < size; i++) {
		String type = this->institution_list[i]->getType();
		if (strcmp(type.c_str(),"group") == 0)
			return true;
	}

	return false;
}

void Organization::checkMembership(const Person& user) {}

void Organization::checkMainInstitution(Institution* inst)
{
	if (inst->valid()) {
		if (this->main_institution->getMembers() < inst->getMembers())
			this->main_institution = inst;
	}
}

size_t Organization::getMembers() const
{
	size_t allMembers = 0;

	size_t size = this->institution_list.getSize();
	for (size_t i = 0; i < size; i++) {
		allMembers += this->institution_list[i]->getMembers();
	}

	return allMembers;
}

void Organization::add_institution(Institution* inst) {
	const String& instType = inst->getType();
	
	if (inst->valid()) {
		if (strcmp(instType.c_str(), "group") == 0) {
			this->institution_list.push_back(inst->clone());
			this->checkMainInstitution(inst);
		}
		else if (strcmp(instType.c_str(), "organization") == 0) {
			if (inst->payer()->getPayerName() == this->payer()->getPayerName()) {
				this->institution_list.push_back(inst->clone());
			}
		}
	}
	else {
		std::cout << "Invalid institution entered!" << std::endl;
	}

}

void Organization::print() {
	std::cout << "Organization Address: " << organization_address << std::endl;
	std::cout << "Num of institutions: " << institution_list.getSize() << std::endl;
}
