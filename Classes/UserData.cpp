#include "UserData.h"
#include <vector>
UserData::UserData() {
	skills =  std::vector<std::string>(1);
}
void UserData::setName(std::string n) {
	name = n;
}
void UserData::setAge(int a) {
	age = a;
}
void UserData::addSkill(std::string sk) {
	skills.push_back(sk);
}
void UserData::showUserData() {
	std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "name: " << name << std::endl;
	std::cout << "age: " << age << std::endl;
	std::cout << "skills: " << std::endl;
	for (size_t i = 0; i < skills.size(); i++)
	{
		std::cout << i + 1 << " : " << skills[i] << std::endl;
	}

}