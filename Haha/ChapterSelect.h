#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "game.h"
USING_NS_CC;  // == using namespace cocos2d

#define TAG_SPRITE_IMAGE 1000
#define TAG_SCROLL  3000

class Chapter :public Layer
{
public:
	static Scene* ChapterScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event);

	Sprite * All;

	bool bisClick;
	int ClickNum;
	
	MenuItemImage *Chapters[4];
	Menu* menu;
	EventListenerTouchOneByOne* listener;

	void StageBtnFunc(Ref* pSender);

	CREATE_FUNC(Chapter);

};