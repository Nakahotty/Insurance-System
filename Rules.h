#pragma once
#include "Person.h"
#include "Group.h"

class Rules {
private:
	static size_t firstDigit(size_t num) {
		while (num >= 10)
			num /= 10;

		return num;
	}
public:
	static void getArmeecRule() {
		std::cout << "RULE : Comparable if the Group ID and the Person ID are the same." << std::endl;
	}

	static void getSDIRule() {
		std::cout << "RULE : Comparable if the first digits of the Group ID and the Person ID match." << std::endl;
	}

	static bool armeecMatchRule(const Person& person, const Group& group) {
		return group.getGroupID() == person.getInsuranceID();
	}

	static bool sdiMatchRule(const Person& person, const Group& group) {
		size_t personID = person.getInsuranceID();
		size_t groupID = group.getGroupID();

		size_t firstDigitPersonID = firstDigit(personID);
		size_t firstDigitGroupID = firstDigit(groupID);

		return firstDigitPersonID == firstDigitGroupID;
	}
};