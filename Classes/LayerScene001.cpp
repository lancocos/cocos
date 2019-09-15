#include "LayerScene001.h"
USING_NS_CC;

Scene* LayerScene001::createScene() {
	return LayerScene001::create();
}

bool LayerScene001::init() {
	if (!Scene::init()) {
		return false;
	}

	return true;
}