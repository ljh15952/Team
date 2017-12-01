#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "game.h"
#include "SingleTone.h"
#include "ChapterSelect.h"
USING_NS_CC;

using namespace CocosDenshion;

Scene* New::NewScene()
{
	auto Scene = Scene::create();
	auto layer = New::create();
	Scene->addChild(layer);
	return Scene;
}

// on "init" you need to initialize your instance
bool New::init()
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
	
	int Money2;
	Screen = 1;
	Money2 = UserDefault::getInstance()->getFloatForKey("money");
	////////////����
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == false)
	{
		VolumeNum = 0.5f;
		SimpleAudioEngine::getInstance()->playBackgroundMusic("changing_times.mp3");
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(VolumeNum);
	}


	////////
	//// ������ ��ư
	auto Quit = MenuItemImage::create("BackBt.png", "BackBt2.png", CC_CALLBACK_1( New::menuCallback, this));
	auto menu = Menu::create(Quit, NULL);
	menu->setPosition(Vec2(100, 650));
	this->addChild(menu, 1);
	///
	

	bisClick = false;
	sexClick1 = false;
	sexClick2 = false;
	OptionClick = false;
	StageClick = false;
	auto Money = Label::createWithTTF("Money", "fonts/Marker Felt.ttf", 24);
	Money->setString(StringUtils::format("%d",Money2));
	Money->setPosition(Vec2(610, 670));
	this->addChild(Money, 1);

	Closet = Sprite::create("Closet.png");
	Closet ->setScale(0.7f);
	Closet->setPosition(Vec2(1000, 65));
	this->addChild(Closet, 1);

	Shop = Sprite::create("Shop.png");
	Shop->setScale(0.7f);
	Shop->setPosition(Vec2(1150, 65));
	this->addChild(Shop, 1);

	Coin = Sprite::create("coin.png");
	Coin->setPosition(Vec2(540, 670));
	this->addChild(Coin, 1);

	All = Sprite::create();
	this->addChild(All, 2);

	PopUp = Sprite::create("4.png");
	PopUp->setPosition(Vec2(650, 370));
	
	All->addChild(PopUp, 2);

	Closebt = Sprite::create("1.png");
	Closebt->setPosition(Vec2(200, 650));
	All->addChild(Closebt, 2);

	Alice1 = Sprite::create("5.png");
	Alice1->setPosition(Vec2(300, 350));
	
	All ->addChild(Alice1, 2);

	Accessory = Sprite::create("6.png");
	Accessory->setPosition(Vec2(800, 400));
	
	All->addChild(Accessory, 2);

	Dress = Sprite::create("7.png");
	Dress->setPosition(Vec2(800, 400));
	
	All->addChild(Dress, 2);
	///////////////  é��1
	AllCp = Sprite::create();
	this->addChild(AllCp, 0);

	BackGround1 = Sprite::create("Bg.png");
	BackGround1->setAnchorPoint(Vec2(0, 0));
	BackGround1->setPosition(Vec2(0, 0));
	AllCp->addChild(BackGround1, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage[i] = Sprite::create(StringUtils::format("stage%d.png",i+1));
		Stage[i]->setAnchorPoint(Vec2(0, 0));
		Stage[i]->setPosition(Vec2(50+(300*i), 240-(25*i)));
		AllCp->addChild(Stage[i], 1);
	}

	
	starone = Sprite::create("star_0.png");
	starone->setPosition(Vec2(183, 270));
	AllCp->addChild(starone, 1);

	startwo = Sprite::create("star_0.png");
	startwo->setPosition(Vec2(470, 240));
	AllCp->addChild(startwo, 1);

	starthree = Sprite::create("star_0.png");
	starthree->setPosition(Vec2(770, 210));
	AllCp->addChild(starthree, 1);

	starfour = Sprite::create("star_0.png");
	starfour->setPosition(Vec2(1060, 180));
	AllCp->addChild(starfour, 1);
	
	//////////////

	//////// é�� 2
	BackGround2 = Sprite::create("Bg2.png");
	BackGround2->setAnchorPoint(Vec2(0, 0));
	BackGround2->setPosition(Vec2(1280, 0));
	AllCp->addChild(BackGround2, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage2[i] = Sprite::create(StringUtils::format("stage2_%d.png", i + 1));
		Stage2[i]->setAnchorPoint(Vec2(0, 0));
		Stage2[i]->setScale(0.9f);
		Stage2[i]->setPosition(Vec2(1330 + (300 * i), 220+(30*i)));
		AllCp->addChild(Stage2[i], 1);
	}
	

	starone2 = Sprite::create("star_0.png");
	starone2->setPosition(Vec2(183+1280, 180));
	AllCp->addChild(starone2, 1);

	startwo2 = Sprite::create("star_0.png");
	startwo2->setPosition(Vec2(485 + 1280, 200));
	AllCp->addChild(startwo2, 1);

	starthree2 = Sprite::create("star_0.png");
	starthree2->setPosition(Vec2(805 + 1280, 230));
	AllCp->addChild(starthree2, 1);

	starfour2 = Sprite::create("star_0.png");
	starfour2->setPosition(Vec2(1090 + 1280, 260));
	AllCp->addChild(starfour2, 1);
	//////

	////é�� 3
	BackGround3 = Sprite::create("Stage3/Bg3.png");
	BackGround3->setAnchorPoint(Vec2(0, 0));
	BackGround3->setPosition(Vec2(2560, 0));
	AllCp->addChild(BackGround3, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage3[i] = Sprite::create(StringUtils::format("Stage3/stage3_%d.png", i + 1));
		Stage3[i]->setAnchorPoint(Vec2(0, 0));
		Stage3[i]->setScale(0.9f);
		Stage3[i]->setPosition(Vec2(2600 + (305 * i), 220));
		AllCp->addChild(Stage3[i], 1);
	}

	starone3 = Sprite::create("star_0.png");
	starone3->setPosition(Vec2(183 + 2560, 180));
	AllCp->addChild(starone3, 1);

	startwo3 = Sprite::create("star_0.png");
	startwo3->setPosition(Vec2(485 + 2560, 200));
	AllCp->addChild(startwo3, 1);

	starthree3 = Sprite::create("star_0.png");
	starthree3->setPosition(Vec2(805 + 2560, 230));
	AllCp->addChild(starthree3, 1);

	starfour3 = Sprite::create("star_0.png");
	starfour3->setPosition(Vec2(1090 + 2560, 260));
	AllCp->addChild(starfour3, 1);
	/////

	////é��4
	BackGround4 = Sprite::create("Bg.png");
	BackGround4->setAnchorPoint(Vec2(0, 0));
	BackGround4->setPosition(Vec2(3840, 0));
	AllCp->addChild(BackGround4, 0);
	///
	OptionAll = Sprite::create();
	this->addChild(OptionAll, 2);

	OptionBt = Sprite::create("option.png");
	OptionBt->setPosition(Vec2(250, 600));
	this->addChild(OptionBt, 1);
	
	OptionPop = Sprite::create("1.png");
	OptionPop->setPosition(Vec2(400, 400));
	OptionPop->setScale(5.0f);
	OptionAll->addChild(OptionPop, 2);

	OptionBack = Sprite::create("2.png");
	OptionBack->setPosition(Vec2(300, 500));
	OptionAll->addChild(OptionBack, 2);

	VolumeUp = Sprite::create("plus.png");
	VolumeUp->setPosition(Vec2(350, 300));
	OptionAll->addChild(VolumeUp,2);
	
	OptionAll->setVisible(false);
	for (int i = 0; i < 2; i++)
	{

		Bt1[i] = Sprite::create("1.png");
		Bt1[i]->setPosition(Vec2(545 + (100 * i), 580));
		All->addChild(Bt1[i], 1);
	}
	
	DressAll = Sprite::create();
	this->addChild(DressAll, 4);
	
	for (int i = 0; i < 10; i++)
	{
		SelectDress[i] = Sprite::create("1.png");
		if(i<5)
		   SelectDress[i]->setPosition(Vec2(600 + (100 * i), 500 ));
		else
		   SelectDress[i]->setPosition(Vec2(100 + (100 * i), 400));
	
		
		DressAll->addChild(SelectDress[i], 4);
	}
	AccAll = Sprite::create();
	this->addChild(AccAll, 4);
	for (int i = 0; i < 10; i++)
	{
		SelectAcc[i] = Sprite::create("1.png");
		if (i<5)
			SelectAcc[i]->setPosition(Vec2(600 + (100 * i), 500));
		else
			SelectAcc[i]->setPosition(Vec2(100 + (100 * i), 400));
		
		AccAll->addChild(SelectAcc[i], 4);
	}

	All->setVisible(false);
	DressAll->setVisible(false);
	AccAll->setVisible(false);

	RtArrow = Sprite::create("RightArrow.png");
	RtArrow->setPosition(Vec2(750, 70));
	this->addChild(RtArrow, 1);

	LtArrow = Sprite::create("LeftArrow.png");
	LtArrow->setPosition(Vec2(250, 70));
	this->addChild(LtArrow, 1);

	this->setTouchEnabled(true); // ��ġȰ��ȭ false�� ��Ȱ��ȭ
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // ������ġ

	
	AllCp->setPosition(Vec2(point::get()->ScreenX, 0));
	CCLOG("Screen X = %d", point::get()->ScreenX);
	
	return true;
}

void New::menuCallback(cocos2d::Ref * pSender)
{
	if (bisClick != true)
	{
		Scene *pScene = Chapter::ChapterScene();
		Director::getInstance()->replaceScene(pScene);
	}
}

bool New::onTouchBegan(Touch* touch, Event* _event)
{

	auto point = touch->getLocation();//Ŭ����ǥ���

	CCLOG("%f %f", point.x, point.y);

	Sex = 0;
	Sex2 = 0;
	if (Closet != nullptr || Shop != nullptr || Closebt != nullptr|| OptionBt !=nullptr|| OptionBack!=nullptr||VolumeUp!=nullptr||RtArrow!=nullptr||LtArrow!=nullptr)
	{

		if (Closet->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet2.png"));

			Sex = 1;
		}
		if (Shop->getBoundingBox().containsPoint(touch->getLocation())&&bisClick!=true)
		{
			Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop2.png"));

			Sex = 2;
		}
		if (Closebt->getBoundingBox().containsPoint(touch->getLocation()))
		{
			All->setVisible(false);
			bisClick = false;
			BackGround1->setOpacity(255);
			BackGround2->setOpacity(255);
			BackGround3->setOpacity(255);
			BackGround4->setOpacity(255);
			DressAll->setVisible(false);
			AccAll->setVisible(false);
		}
		if (OptionBt->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			OptionClick = true;
			OptionBt ->setTexture(Director::getInstance()->getTextureCache()->addImage("1.png"));
			
		}
		if (OptionBack->getBoundingBox().containsPoint(touch->getLocation()))
		{
			OptionAll->setVisible(false);
			bisClick = false;
		}
		if (VolumeUp->getBoundingBox().containsPoint(touch->getLocation())&&OptionAll->isVisible()==true)
		{
			CCLOG("Volume Up");
			VolumeNum += 0.1;
			SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(VolumeNum);
		}
		if (RtArrow->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow2.png"));
			Sex2 = 1;
			
		}
		if (LtArrow->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow2.png"));
			Sex2 = 2;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (Bt1[i] != nullptr&&bisClick==true)
		{
			if (Bt1[0]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				Dress->setZOrder(3);
				Accessory->setZOrder(2);
				DressAll->setVisible(true);
				AccAll->setVisible(false);
			}
			if (Bt1[1]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				Dress->setZOrder(2);
				Accessory->setZOrder(3);
				DressAll->setVisible(false);
				AccAll->setVisible(true);
			}
		}

	}
	
	for (int i = 0; i < 10; i++)
	{
		if (SelectDress[i] != nullptr&&SelectAcc[i] != nullptr)
		{
			if (SelectDress[i]->getBoundingBox().containsPoint(touch->getLocation())&&point::get()->AbleDress[i]==true)
			{
				ClickNum = i;
				sexClick1 = true;
			}
			if (SelectAcc[i]->getBoundingBox().containsPoint(touch->getLocation())&&point::get()->AbleAcc[i] ==true)
			{
				ClickNum = i;
				sexClick2 = true;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (Stage[i] != nullptr&& bisClick != true)
		{
			if (Stage[i]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				StageClick = true;
				StageNum = i;
			}
		}
	}
	
		return true;
}



void New::onTouchMoved(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();//Ŭ����ǥ���
	if (sexClick1 == true)
	{
		SelectDress[ClickNum]->setZOrder(5);
		SelectDress[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
	if (sexClick2 == true)
	{
		SelectAcc[ClickNum]->setZOrder(5);
		SelectAcc[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
}

void New::onTouchEnded(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();
	//// ����ȯ
	//Scene *pScene = HelloWorld::createScene();
	//Director::getInstance()->replaceScene(pScene);
	////	
	if (Closet->getBoundingBox().containsPoint(touch->getLocation()) && Sex == 1)
	{
		MenuClick(1);
	}
	if (Shop->getBoundingBox().containsPoint(touch->getLocation()) && Sex == 2&&bisClick!=true)
	{
		MenuClick(2);
	}
	//////
	if (RtArrow->getBoundingBox().containsPoint(touch->getLocation())&& Sex2 ==1)
	{
		ScreenMove(-1);
	}
	if (LtArrow->getBoundingBox().containsPoint(touch->getLocation())&& Sex2 ==2)
	{
		ScreenMove(1);
	}
	///////
	if (sexClick1 == true)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i<5)
				SelectDress[i]->setPosition(Vec2(600 + (100 * i), 500));
			else
				SelectDress[i]->setPosition(Vec2(100 + (100 * i), 400));
		}
		sexClick1 = false;
	}
	if (sexClick2 == true)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i<5)
				SelectAcc[i]->setPosition(Vec2(600 + (100 * i), 500));
			else
				SelectAcc[i]->setPosition(Vec2(100 + (100 * i), 400));
		}
		sexClick2 = false;
	}
	/////////////////////////////
	if (OptionClick == true)
	{
		if (OptionBt->getBoundingBox().containsPoint(touch->getLocation()))
		{
			OptionAll->setVisible(true);
			bisClick = true;

		}
			OptionClick = false;
			
			OptionBt->setTexture(Director::getInstance()->getTextureCache()->addImage("Option.png"));
	}
	if (StageClick == true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (Stage[i]->getBoundingBox().containsPoint(touch->getLocation())&&StageNum==i)
			{
				CCLOG("stage %d", i+1);
			}
		}
			StageClick = false;
			StageNum = -1;
	}
	
	Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet.png"));
	Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop.png"));
	RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow.png"));
	LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow.png"));

}
void New::MenuClick(int Clicknum)
{
	
		if (Clicknum == 1) // ���� Ŭ��
		{
			bisClick = true;
			DressAll->setVisible(true);
			All->setVisible(true);
			BackGround1->setOpacity(140);
			BackGround2->setOpacity(140);
			BackGround3->setOpacity(140);
			BackGround4->setOpacity(140);
		
			DressOn();
		}
		else if (Clicknum == 2) // ���� Ŭ�� 
		{
			//// ����ȯ
			Scene *pScene = HelloWorld::createScene();
			Director::getInstance()->replaceScene(pScene);
			////	

		}
}

void New::DressOn()
{
	for (int i = 0; i < 100; i++)
	{
		if (point::get()->DressArr[i] != NULL&&point::get()->DressArr[i] > 0)
		{
			SelectDress[point::get()->DressArr[i] - 1]->setTexture(Director::getInstance()->getTextureCache()->addImage("2.png"));
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (point::get()->AccArr[i] != NULL&&point::get()->AccArr[i] > 0)
		{
			SelectAcc[point::get()->AccArr[i] - 1]->setTexture(Director::getInstance()->getTextureCache()->addImage("2.png"));
		}
	}
	
	
}

void New::ScreenMove(int Num)
{
	if (point::get()->ScreenX < 0&&Num==1)
	{
		Screen += Num;
		point::get()->ScreenX += 1280 * Num;
		AllCp->runAction(MoveBy::create(0.1, Vec2(1280 * Num, 0)));
	}
	else if(point::get()->ScreenX > -3840 && Num == -1)
	{
		Screen += Num;
		point::get()->ScreenX += 1280 * Num;
		AllCp->runAction(MoveBy::create(0.1, Vec2(1280 * Num, 0)));
	}
}