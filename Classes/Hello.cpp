#include "Hello.h"
#include <json/document.h>
#include "Userdata.h"
USING_NS_CC;
Scene* Hello::createScene() {
	return Hello::create();
}
bool Hello::init() {
	if (!Scene::init()) {
		return false;
	}
	std::string filepath = FileUtils::getInstance()->fullPathForFilename("hello.json");
	CCLOG(filepath.c_str());
	std::string content = FileUtils::getInstance()->getStringFromFile(filepath);
	CCLOG(content.c_str());
	rapidjson::Document doc;
	doc.Parse<0>(content.c_str());
	if (doc.HasParseError()) {
		CCLOG("parse json error!");
		return false;
	}
	if (!doc.IsObject()) {
		CCLOG("###");
		return false;
	}
	UserData* user = new UserData();

	if (doc.HasMember("name")) {
		CCLOG("has name");
		const rapidjson::Value& v1 = doc["name"];
		std::string name = v1.GetString();
		CCLOG("%s", name);
		user->setName(name);
	}

	else {
		CCLOG("has no name");
	}
	if (doc.HasMember("age")) {
		rapidjson::Value& const v2 = doc["age"];
		int age = v2.GetInt();
		user->setAge(age);
	}
	else {
		CCLOG("has no age");
	}
	if (doc.HasMember("skills")) {
		rapidjson::Value& v3 = doc["skills"];
		CCLOG("size is %d", v3.Size());
		if (v3.IsArray() && v3.Size() > 0) {
			for (int i = 0; i < v3.Size(); i++) {
				rapidjson::Value& v3v = doc["skills"][i];
				std::string sk = v3v.GetString();
				CCLOG("%d = %s", i, sk);
				user->addSkill(sk);
			}
		}
	}
	
  user->showUserData();
	return true;
}