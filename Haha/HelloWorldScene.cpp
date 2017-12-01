#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include "time.h"
#include"SingleTone.h"
USING_NS_CC;

using namespace CocosDenshion;



Scene* HelloWorld::createScene()
{
	auto Scene = Scene::create();
	auto layer = HelloWorld::create();
	Scene->addChild(layer);
	return Scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	srand(time(nullptr));
    

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치

	
	
	close = true;
	bisclick = false;
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object

	MyMoney = UserDefault::getInstance()->getFloatForKey("money");
	DressNum = UserDefault::getInstance()->getFloatForKey("DressNum");
	AccNum = UserDefault::getInstance()->getFloatForKey("AccNum");

	auto Quit = MenuItemImage::create("BackBt.png", "BackBt2.png", CC_CALLBACK_1(HelloWorld::menuCallback, this));
	auto menu = Menu::create(Quit, NULL);
	menu->setPosition(Vec2(100, 650));
	this->addChild(menu, 1);
	
	item1 = Sprite::create("1.png");
	item1->setPosition(Vec2(400, 250));
	
	this->addChild(item1, 1);

	item2 = Sprite::create("1.png");
	item2->setPosition(Vec2(850, 250));
	
	this->addChild(item2, 1);

	All = Sprite::create();
	this->addChild(All, 2);
	All->setVisible(false);
	item3 = Sprite::create("3.png");
	item3->setPosition(Vec2(635, 320));
	
	All->addChild(item3, 2);

	Button = Sprite::create("2.png");
	Button->setPosition(Vec2(640, 130));
	All->addChild(Button, 2);

	

	Money = Label::createWithTTF("Money", "fonts/Marker Felt.ttf", 24);
	Money->setString(StringUtils::format("My  Money: %d",MyMoney));
	Money->setPosition(Vec2(650, 650));
	this->addChild(Money, 1);
	
	Getdress = Label::createWithTTF("Buy  Dress", "fonts/Marker Felt.ttf", 24);
	Getdress->setPosition(Vec2(400, 400));
	
	this->addChild(Getdress, 1);

	Rand = Label::createWithTTF("Random", "fonts/Marker Felt.ttf", 24);
	R = rand() % 10;
	//Rand->setString(StringUtils::format("%d", R));
	Rand->setPosition(Vec2(600, 350));
	this->addChild(Rand, 2);

	Getaccessory = Label::createWithTTF("Buy  accessory", "fonts/Marker Felt.ttf", 24);
	Getaccessory->setPosition(Vec2(850, 400));
	
	this->addChild(Getaccessory, 1);
 

	scheduleUpdate();
	return true;
}

void HelloWorld::menuCallback(cocos2d::Ref * pSender)
{
	if (bisclick != true)
	{
		UserDefault::getInstance()->setFloatForKey("money", MyMoney);
		UserDefault::getInstance()->setFloatForKey("DressNum", DressNum);
		UserDefault::getInstance()->setFloatForKey("AccNum", AccNum);
		Scene *pScene = New::NewScene();
		Director::getInstance()->replaceScene(pScene);
	}
}
void HelloWorld::onExit()
{
	Layer::onExit();
	//DressNum = 0;
	UserDefault::getInstance()->setFloatForKey("money", MyMoney);
	UserDefault::getInstance()->setFloatForKey("DressNum", DressNum);
	UserDefault::getInstance()->setFloatForKey("AccNum", AccNum);
}
void HelloWorld::onEnter()
{
	Layer::onEnter();
	
}

bool HelloWorld::onTouchBegan(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();

	CCLOG("%f %f", point.x, point.y);
	CCLOG("%d", DressNum);
	Sex = 0;

	if (item1 != nullptr||item2!=nullptr||Button!=nullptr)
	{
		if (close == true)
		{
			if (item1->getBoundingBox().containsPoint(touch->getLocation()))
			{
				item1->setTexture(Director::getInstance()->getTextureCache()->addImage("2.png"));
				bisclick = true;
				Sex = 1;
			}
			if (item2->getBoundingBox().containsPoint(touch->getLocation()))
			{
				item2->setTexture(Director::getInstance()->getTextureCache()->addImage("2.png"));
				bisclick = true;
				Sex = 2;
			}
		}
			if (Button->getBoundingBox().containsPoint(touch->getLocation()))
			{
				All->setVisible(false);
				close = true;
				bisclick = false;
			}
	}

	
	
	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event*_event)
{
	auto point = touch->getLocation();



	
	

}

void HelloWorld::onTouchEnded(Touch* touch, Event*_event)
{
		if (item1->getBoundingBox().containsPoint(touch->getLocation())&& Sex == 1)
		{
			ClickBuy(1);
			JAJAN();

		}
		if (item2->getBoundingBox().containsPoint(touch->getLocation())  && Sex == 2)
		{
			ClickBuy(2);
			JAJAN();
		}
	
	
	item1->setTexture(Director::getInstance()->getTextureCache()->addImage("1.png"));
	item2->setTexture(Director::getInstance()->getTextureCache()->addImage("1.png"));
	//Sex = 0;
	
}


void HelloWorld::update(float dt)
{
	static float t = 0;
	


}

void HelloWorld::ClickBuy(int Clicknum)
{
	if (bisclick == true)
	{
		if (Clicknum == 1 && MyMoney >= 1000)
		{
			MyMoney -= 1000;
			Money->setString(StringUtils::format("My  Money: %d", MyMoney));
			R = rand() % 10+1;
			Rand->setString(StringUtils::format("%d", R));
			point::get()->DressArr[DressNum] = R;
			point::get()->AbleDress[R-1] = true;
			DressNum++;
			

		}
		else if (Clicknum == 2 && MyMoney >= 3000)
		{
			MyMoney -= 3000;
			Money->setString(StringUtils::format("My  Money: %d", MyMoney));
			R = rand() % 10+1;
			Rand->setString(StringUtils::format("%d", R));
			point::get()->AccArr[AccNum] = R;
			point::get()->AbleAcc[R - 1] = true;
			AccNum++;
			
		}
	}

}

void HelloWorld::JAJAN()
{
	All->setVisible(true);
	close = false;
	bisclick = true;
	
	CCLOG("%d", close);
}


