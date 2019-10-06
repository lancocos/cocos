#include "ShakeScreen.h"

cocos2d::Scene* ShakeScreen::createScene(){
	return ShakeScreen::create();
}
bool ShakeScreen::init() {
	if (!cocos2d::Scene::init()) {
		return false;
	}
	return true;
}