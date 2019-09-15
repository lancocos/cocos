#include "Hello.h"
USING_NS_CC;
Scene* Hello::createScene() {
	auto s = Scene::create();
	return Hello::create();
}
bool Hello::init() {
	if (!Scene::init()) {
		return false;
	}
	return true;
}