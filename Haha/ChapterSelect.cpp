#include"ChapterSelect.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include"SingleTone.h"
USING_NS_CC;

using namespace CocosDenshion;

Scene* Chapter::ChapterScene()
{
	auto Scene = Scene::create();
	auto layer = Chapter::create();
	Scene->addChild(layer);
	return Scene;
}

// on "init" you need to initialize your instance
bool Chapter::init()
{
	//////////////////////////////
	// 1. super init first

	if (!Layer::init())
	{
		return false;
	}
	srand(time(NULL));

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치
	
	
	

	bisClick = false;
	ClickNum = -1;
	
	for (int i = 0; i < 4; i++)
	{
		Chapters[i] = Sprite::create("1.png");
		Chapters[i]->setPosition(Vec2(300 + (200 * i), 300));
		this->addChild(Chapters[i], 1);
	}

	return true;
}





bool Chapter::onTouchBegan(Touch* touch, Event* _event)
{

	auto point = touch->getLocation();//클릭좌표얻기

	CCLOG("%f %f", point.x, point.y);

	for (int i = 0; i < 4; i++)
	{
		if (Chapters[i] != nullptr)
		{
			if (Chapters[i]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
			}
		}
	}
	return true;
}

void Chapter::onTouchEnded(Touch* touch, Event* _event)
{
	
	for (int i = 0; i < 4; i++)
	{
		if (Chapters[i]->getBoundingBox().containsPoint(touch->getLocation())&&ClickNum==i)
		{
				point::get()->ScreenX = -(1280 * i);
				Scene *pScene = New::NewScene();
				Director::getInstance()->replaceScene(pScene);
		}
	}
	ClickNum = -1;
}




void Chapter::onTouchMoved(Touch* touch, Event* _event)
{

}

