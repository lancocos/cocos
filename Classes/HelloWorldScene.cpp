/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto glProgram = GLProgram::createWithFilenames("shaders/vert.vsh","shaders/frag.fsh");
	auto state = GLProgramState::getOrCreateWithGLProgram(glProgram);
	setGLProgramState(state);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
		//sprite->setScale(0.3f, 0.3f);
        // add the sprite as a child to this layer
		this->graySprite(sprite);
        this->addChild(sprite, 0);
    }

	auto lab1 = Label::createWithTTF("hello world","fonts/Marker Felt.ttf",30);
	lab1->setPosition(Vec2(80, 200));
	this->addChild(lab1);
	auto mb = MoveTo::create(10.0f,Vec2(400,0));
	auto rt = RotateBy::create(10.0f, Vec3(0,100, 100));
	lab1->runAction(mb);
	lab1->runAction(rt);

	TTFConfig ttfconf;
	ttfconf.fontFilePath = "fonts/Marker Felt.ttf";
	ttfconf.fontSize = 20;
	auto m1 = Label::createWithTTF(ttfconf, "lancocos@gmail.com");
	m1->setPosition(Vec2(300, 50));
	m1->setColor(Color3B(Color3B::RED ));
	this->addChild(m1);

	auto i1 = MenuItemImage::create("CloseNormal.png","CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
	auto i2 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));


	auto menu1 = Menu::create(i1,i2, NULL);
	menu1->setPosition(Vec2(200, 30));
	this->addChild(menu1);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) {
	_customCommand.init(_globalZOrder, transform, flags);
	_customCommand.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
}
void HelloWorld::onDraw(const cocos2d::Mat4& transform, uint32_t flags) {
	return;
	auto glProgram = getGLProgram();
	glProgram->use();
	glProgram->setUniformsForBuiltins();


	// 绘制三角形
	auto size = Director::getInstance()->getWinSize();
	// 三个顶点的坐标
	float vertercies[] = { 0, 0,
		size.width, 0,
		size.width / 2, size.height };
	// 三个顶点的RGBA
	float color[] = { 0, 1, 0, 1,
		1, 0, 0, 1,
		0, 0, 1, 1 };


	//激活名字为position和color的vertex attribute
	GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);


	//分别给position和color指定数据源
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertercies);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);


	//绘制三角形，所谓的draw call就是指这个函数调用
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//通知cocos2d-x 的renderer，让它在合适的时候调用这些OpenGL命令
	CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
	//如果出错了，可以使用这个函数来获取出错信息
	CHECK_GL_ERROR_DEBUG();
}

void HelloWorld::graySprite(Sprite * sp) {
	auto * p = GLProgram::createWithFilenames("shaders/gray.vsh", "shaders/gray.fsh");
	p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	p->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
	p->link();
	p->updateUniforms();
	sp->setShaderProgram(p);
}
