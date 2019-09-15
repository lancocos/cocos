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
	auto spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("f1.plist");
	//auto ss1 = Sprite::createWithSpriteFrameName("i1.png");
	//ss1->setPosition(Vec2(200, 100));
	//this->addChild(ss1);
	auto pinfo = AutoPolygon::generatePolygon("i1.png");
	auto ss1 = Sprite::create(pinfo);
	ss1->setPosition(Vec2(200, 100));
	this->addChild(ss1);
	auto mt = MoveTo::create(10, Vec2(200, 200));
	ss1->runAction(mt);
	auto myLabel = Label::createWithBMFont("markerFelt.fnt", "Your Text");
	myLabel->setPosition(Vec2(150, 200));
	myLabel->enableGlow(Color4B::YELLOW);
	this->addChild(myLabel);
	auto func = []() {CCLOG("ADSD");};
	auto label1 = LabelTTF::create("stop","Arial",14);
	auto mux = MenuItemLabel::create(label1);
	auto mmm = Menu::create(mux, NULL);
	mmm->setPosition(Vec2(300, 200));
	this->addChild(mmm);

	return true;
}
void MyScene000::toScene(cocos2d::Ref* pSender) {
	CCLOG("CLOSE ITEM");
	auto director = Director::getInstance();
	auto s = MyScene000::create();
	Director::getInstance()->replaceScene(TransitionFlipX::create(2, s));
}