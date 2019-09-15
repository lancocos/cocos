#include "MyScene000.h"
#include "cocos2d.h"
//#include "LayerScene001.h"
#include "Hello.h"
USING_NS_CC;

Scene* MyScene000::createScene() {
	auto s = Scene::create();
	
	return MyScene000::create();
}

bool MyScene000::init() {
	if (!Scene::initWithPhysics()) {
		return false;
	}
	auto size = Director::getInstance()->getVisibleSize();
	CCLOG("DADSADASDASDASD");
	auto item1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(MyScene000::toScene, this));
	auto mu = Menu::create(item1, NULL);
	mu->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(mu);
	auto sp = Sprite::create("i1.png");
	sp->setPosition(Vec2(100, 100));
	this->addChild(sp);
	auto sp2 = Sprite::create("i1.png", Rect(0, 0, 50, 50));
	sp2->setPosition(Vec2(150, 100));
	this->addChild(sp2);
	return true;
}
void MyScene000::toScene(cocos2d::Ref* pSender) {
	CCLOG("CLOSE ITEM");
	auto director = Director::getInstance();
	auto s = MyScene000::create();
	//Director::getInstance()->replaceScene(s);
}