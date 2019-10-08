#include "Hello.h"
#include <json/document.h>
#include "Userdata.h"
#include <ui/CocosGUI.h>
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
	char* const  str = "hello";
	CCLOG(str);
	auto btn = cocos2d::ui::Button::create("Button_Normal.png","Button_Press.png","Button_Disable.png");
	btn->setTitleText("click me!@");
	btn->setTitleColor(cocos2d::Color3B::RED);
	btn->setPosition(cocos2d::Vec2(100, 100));
	btn->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		CCLOG("####");
		//auto mb = MoveBy::create(10.0f, Vec2(200, 200));
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			
			//btn->runAction(mb);
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	this->addChild(btn);
	auto cb = ui::CheckBox::create("CheckBox_Normal.png", "CheckBox_Disable.png","CheckBoxNode_Disable.png", "CheckBoxNode_Disable.png", "CheckBoxNode_Normal.png");
	cb->setPosition(Vec2(100, 150));
	this->addChild(cb);
	auto lb = ui::LoadingBar::create("loadingbar.png");
	lb->setPosition(Vec2(100, 200));
	lb->setDirection(ui::LoadingBar::Direction::RIGHT);
	lb->setPercent(100);
	this->addChild(lb);
	auto slider = ui::Slider::create();
	slider->loadBarTexture("Slider_Back.png");
	slider->loadSlidBallTextures("SliderNode_Normal.png","SliderNode_Press.png","SliderNode_Disable.png");
	slider->loadProgressBarTexture("Slider_PressBar.png");
	slider->setPosition(Vec2(300, 100));
	slider->addTouchEventListener([&](Ref* pSender,ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "slider moved" << std::endl;
			break;
		default:
			break;
		}
	});
	this->addChild(slider);
	auto edit = ui::TextField::create("default ÖÐÎÄ","Arial",12);
	edit->setPosition(Vec2(300, 300));
	//edit->setSize(Size(100, 100));
	edit->setContentSize(Size(100, 100));
	this->addChild(edit);


	auto sp = cocos2d::Sprite::create("Helloworld.png");
	sp->setPosition(cocos2d::Vec2(200, 240));
	//this->addChild(sp);
	
	UserData* user = new UserData;

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
	/*
	if (doc.HasMember("sprites")) {
		rapidjson::Value& sp = doc["sprites"];
		if (sp.IsArray && sp.Size() > 0) {
			for (int i = 0; i < sp.Size(); i++) {
				//rapidjson::Value& spv = doc["sprite"][i];
			}
		}
	}
	*/
	
  user->showUserData();
	return true;
}