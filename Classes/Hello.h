#ifndef __HELLO_h__
#define __HELLO_h__
#include "cocos2d.h"
USING_NS_CC;
class Hello :public Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Hello);
};
#endif // !__HELLO_h__
