#ifndef __SHAKESCREEN__H__
#define __SHAKESCREEN__H__
#include "cocos2d.h"

class ShakeScreen : public cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(ShakeScreen);

};

#endif