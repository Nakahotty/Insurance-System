#pragma once
#include "Person.h"
#include <functional>

class Group;

class Payer {
private:
	using matchRule = std::function<bool(const Person&, const Group&)>;

	String payer_name;
	matchRule payer_member_rule;

	// matchRule payer_member_rule = [](const Person& person, const Group& group) -> bool { return person.getInsuranceID() == group.getGroupID(); };
public:
	Payer();
	Payer(const String& payer_name, const matchRule payer_member_rule);
	Payer* clone();
	String getPayerName() const;
	const matchRule& getMatchRule() const { return this->payer_member_rule; };

	void setPayerName(const String& name);
	void setMatchRule(matchRule rule);
	// void checkClient(const Person& person) { if (this->payer_member_rule(person, )) { this->clients++; } }

	void print();
};