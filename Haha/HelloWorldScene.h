#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();
    
    // a selector callback
 
	
	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event);
	void update(float dt);

	void menuCallback(cocos2d::Ref* Psender);
	void ClickBuy(int Clicknum);
	void JAJAN();
	Label * Money;
	Label * Getdress;
	Label * Getaccessory;
	Label * Rand;
	Sprite * item1;
	Sprite * item2;
	Sprite * item3;
	Sprite * Button;
	Sprite * All;
	
	bool close;
	bool bisclick;
	int Sex;
	int MyMoney;
	int R;
	int DressNum;
	int AccNum;
	virtual void onExit();
	virtual void onEnter();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
