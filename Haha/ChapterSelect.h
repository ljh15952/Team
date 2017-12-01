#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
#include "game.h"
USING_NS_CC;  // == using namespace cocos2d


class Chapter :public Layer
{
public:
	static Scene* ChapterScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event);

	bool bisClick;
	int ClickNum;
	
	Sprite *Chapters[4];

	CREATE_FUNC(Chapter);

};