#include "Organization.h"
#include "Rules.h"

Institution* clear_institutions(Organization* institution) {
	Vector<Institution*> inst_list = institution->getInstitutionList();
	size_t size = inst_list.getSize();

	for (size_t i = 0; i < size; i++) {
		if (!inst_list[i]->valid()) {
			inst_list.pop_at(i);
		}
			
	}

	return institution->clone();
}

Institution* find_most_popular_institution(Organization* institution, Vector<Person> people) {
	Vector<Institution*> inst_list = institution->getInstitutionList();
	Institution* most_popular = inst_list[0];
	size_t most_popular_members = most_popular->getMembers();
	size_t institution_size = inst_list.getSize();

	for (size_t i = 0; i < institution_size; i++) {
		if (inst_list[i]->valid()) {
			if (inst_list[i]->getMembers() > most_popular_members)
				most_popular = inst_list[i];
		}
	}

	return most_popular->clone();
}


// При създаването на нова институция се увеличава ID
size_t Institution::institution_id = 0;

int main() {
	// Някакви варненски пичове
	Person nasko("Atanaschoo", 77719);
	Person nasko2("Nasko", 77719);
	Person milen("Milenskiq", 77719);
	nasko.print(); std::cout << std::endl;

	// Инициализиране на застрахователи
	Payer* armeec = new Payer();
	armeec->setPayerName("Armeec OOD");
	armeec->setMatchRule(Rules::armeecMatchRule);

	Payer* SDI = new Payer();
	SDI->setPayerName("SDI Broker");
	SDI->setMatchRule(Rules::sdiMatchRule);

	// Инициализиране на институции
	Vector<Institution*> institutions;
	Institution* institution = new Group(77719, armeec);
	Institution* institution2 = new Group(700, SDI);
	Institution* institution3 = new Group(3444,armeec);

	// Работи и с push_back и с add_institution
	institutions.push_back(institution);
	institutions.push_back(institution2);
	 
	// Organization тестове 
	Institution* organization = new Organization(institutions, "Varna, Mladost ul. Nasko Traicho 28");
	static_cast<Organization*> (organization)->add_institution(institution3);
	
	organization->payer();

	// Армеец дали е валидна, съдържа Наско, и дали е свързана със застрахователя
	std::cout << nasko.getName() << " is member: " << institution->has_member(nasko) << std::endl;
	Payer* armeecPayer = institution->payer();

	// Group members тест 
	institution->checkMembership(nasko);
	institution->checkMembership(nasko2);
	institution->checkMembership(milen);
	institution->print(); 
	Rules::getArmeecRule(); std::cout << std::endl;

	std::cout << "Members of all institutions: " << organization->getMembers() << std::endl;  // 3 -> nasko,nasko2,milen

	// SDI --||--
	std::cout << nasko2.getName() << " is member: " << institution2->has_member(nasko2) << std::endl;
	Payer* sdiPayer = institution2->payer();
	institution2->checkMembership(nasko2);
	institution2->checkMembership(milen);
	institution2->print();
	Rules::getSDIRule(); std::cout << std::endl;

	// Идентификатор тест
	std::cout << "Institutions created so far: " << organization->getInstitutionID() << std::endl << std::endl;

	// Функции тестове
	Institution* cleared = clear_institutions(static_cast<Organization*> (organization));
	cleared->print(); 
	std::cout << std::endl;

	Vector<Person> people;
	people.push_back(nasko);
	people.push_back(nasko2);
	people.push_back(milen);
	Institution* most_popular = find_most_popular_institution(static_cast<Organization*> (organization), people);
	
	std::cout << "Most popular institution: " << std::endl;
	most_popular->print();

	return 0;
}