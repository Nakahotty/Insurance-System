#include "Payer.h"

Payer::Payer() {
	this->payer_name = "";
}

Payer::Payer(const String& payer_name, const matchRule payer_member_rule)
{
	this->payer_name = payer_name;
	this->payer_member_rule = payer_member_rule;
}

Payer* Payer::clone()
{
	return new Payer(*this);
}

String Payer::getPayerName() const
{
	return this->payer_name;
}

void Payer::setPayerName(const String& name)
{
	this->payer_name = name;
}

void Payer::setMatchRule(matchRule rule)
{
	this->payer_member_rule = rule;
}

void Payer::print()
{
	std::cout << "Payer name: " << this->payer_name << std::endl;
}
