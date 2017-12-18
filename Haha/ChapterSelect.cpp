#include"ChapterSelect.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include"SingleTone.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

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
	//listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(Chapter::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//auto listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(Chapter::onTouchBegan, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	//All = Sprite::create();
	//this->addChild(All, 1);
	//
	//스크롤 뷰에 넣을 레이어 


	auto layer = LayerColor::create(ccc4(255,255,255,255));
	layer->setContentSize(Size(1280 * 4, 720));
	
	///
		auto s = Sprite::create("stage2/Bg2.png");
		s->setAnchorPoint(Vec2(0, 0));
		s->setPosition(Vec2(1280, 0));
		layer->addChild(s);

		auto s1 = Sprite::create("stage1/Bg.png");
		s1->setAnchorPoint(Vec2(0, 0));
		layer->addChild(s1);

		auto s2 = Sprite::create("stage3/Bg3.png");
		s2->setAnchorPoint(Vec2(0, 0));
		s2->setPosition(Vec2(2560, 0));
		layer->addChild(s2);


		auto s3 = Sprite::create("stage3/Bg3.png");
		s3->setAnchorPoint(Vec2(0, 0));
		s3->setPosition(Vec2(1280*3, 0));
		layer->addChild(s3);
	///
	for (int i = 0; i < 4; i++)
	{
		Chapters[i] = MenuItemImage::create("1.png", "1.png",CC_CALLBACK_1(Chapter::StageBtnFunc,this));
		Chapters[i]->setPosition(Vec2(300 + (1280 * i), 500));
		Chapters[i]->setTag(i);
		menu = Menu::create(Chapters[i], NULL);
		menu->setPosition(Vec2(0, 0));
		layer->addChild(menu, 0);
	}


	auto Sc = ScrollView::create(Size(1280, 720), layer);
	Sc->setDirection(ScrollView::Direction::HORIZONTAL);
	Sc->setBounceable(false);
	Sc->setTag(TAG_SCROLL);
	this->addChild(Sc);


	bisClick = false;
	ClickNum = -1;



	return true;
}
void Chapter::StageBtnFunc(Ref* pSender)
{
	for (int i = 0; i < 4; i++)
	{
		if (((MenuItemImage*)pSender)->getTag() == i)
		{
			CCLOG("%d", Chapters[i]->getTag());
			ClickNum = Chapters[i]->getTag();
		}
	}
	/*for (int i = 0; i < 4; i++)
	{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
	}*/
	for (int i = 0; i < 4; i++)
	{
		if (ClickNum == i)
		{
			point::get()->ScreenX = -(1280 * Chapters[i]->getTag());
			Scene *pScene = New::NewScene();
			Director::getInstance()->replaceScene(pScene);
		}
	}
	
}

bool Chapter::onTouchBegan(Touch* touch, Event* _event)
{

	Vec2 location = Vec2(touch->getLocation().x, touch->getLocation().y);

	CCLOG("%f %f", location.x, location.y);


	/*auto scroll = (ScrollView*)this->getChildByTag(TAG_SCROLL);
	auto layer = (Layer*)scroll->getContainer();
	auto spr = (Sprite*)layer->getChildByTag(TAG_SPRITE_IMAGE);

	Rect sprRect = spr->getBoundingBox();

	Rect scrollSprRect = Rect(sprRect.origin.x + scroll->getContentOffset().x,
		sprRect.origin.y + scroll->getContentOffset().y,
		sprRect.size.width,
		sprRect.size.height
	);

	if (scrollSprRect.containsPoint(location))
	{
		CCLOG("SDSD");
	}
	else
	{
		CCLOG("NOT Touch");
	}
*/




	//for (int i = 0; i < 4; i++)
	//{
	//	if (Chapters[i] != nullptr)
	//	{
	//		if (Chapters[i]->getBoundingBox().containsPoint(touch->getLocation()))
	//		{
	//			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
	//			ClickNum = i;
	//		}
	//	}
	//}
	return true;
}

void Chapter::onTouchEnded(Touch* touch, Event* _event)
{
	for (int i = 0; i < 4; i++)
	{
		if (Chapters[i]->getBoundingBox().containsPoint(touch->getLocation()) && ClickNum == i)
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

