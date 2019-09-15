#ifndef __MYSCENE01__H
#define __MYSCENE01__H
#include "cocos2d.h"
USING_NS_CC;
class MyScene000:public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyScene000);
	void toScene(cocos2d::Ref* pSender);

};
#endif
