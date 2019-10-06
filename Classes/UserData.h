#ifndef USER_DATA__H
#define USER_DATA__H
#include <iostream>
#include <vector>
class UserData {
	private:
		std::string name;
		int age;
		std::vector<std::string> skills;
public:
	UserData();
	void setName(std::string name);
	void setAge(int age);
	void addSkill(std::string s);
	void showUserData();

};
#endif // !USER_DATA__H
