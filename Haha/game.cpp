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
	////////////음악
	if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == false)
	{
		VolumeNum = 0.5f;
		SimpleAudioEngine::getInstance()->playBackgroundMusic("changing_times.mp3");
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(VolumeNum);
	}


	////////
	//// 나가기 버튼
	auto Quit = MenuItemImage::create("BackBt.png", "BackBt2.png", CC_CALLBACK_1( New::menuCallback, this));
	auto menu = Menu::create(Quit, NULL);
	menu->setPosition(Vec2(100, 650));
	this->addChild(menu, 2);
	///
	

	bisClick = false;
	closetClick = false;
	sexClick1 = false;
	sexClick2 = false;
	OptionClick = false;
	StageClick = false;
	StageClick2 = false;
	auto Money = Label::createWithTTF("Money", "fonts/Marker Felt.ttf", 24);
	Money->setString(StringUtils::format("%d",Money2));
	Money->setPosition(Vec2(610, 670));
	this->addChild(Money, 2);

	Closet = Sprite::create("Closet.png");
	Closet ->setScale(0.7f);
	Closet->setPosition(Vec2(1000, 65));
	this->addChild(Closet, 2);

	Shop = Sprite::create("Shop.png");
	Shop->setScale(0.7f);
	Shop->setPosition(Vec2(1150, 65));
	this->addChild(Shop, 2);

	Coin = Sprite::create("coin.png");
	Coin->setPosition(Vec2(540, 670));
	this->addChild(Coin, 2);

	All = Sprite::create();
	this->addChild(All, 3);

	PopUp = Sprite::create("4.png");
	PopUp->setPosition(Vec2(650, 370));
	
	All->addChild(PopUp, 2);

	Closebt = Sprite::create("1.png");
	Closebt->setPosition(Vec2(200, 650));
	All->addChild(Closebt, 2);

	Alice1 = Sprite::create("5.png");
	Alice1->setPosition(Vec2(390, 350));
	
	All ->addChild(Alice1, 5);

	Accessory = Sprite::create("6.png");
	Accessory->setPosition(Vec2(800, 400));
	
	All->addChild(Accessory, 2);

	Dress = Sprite::create("7.png");
	Dress->setPosition(Vec2(800, 400));
	
	All->addChild(Dress, 2);
	///////////////  챕터1
	AllCp = Sprite::create();
	this->addChild(AllCp, 1);

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

	//////// 챕터 2
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

	////챕터 3
	BackGround3 = Sprite::create("Bg3.png");
	BackGround3->setAnchorPoint(Vec2(0, 0));
	BackGround3->setPosition(Vec2(2560, 0));
	AllCp->addChild(BackGround3, 0);

	for (int i = 0; i < 4; i++)
	{
		Stage3[i] = Sprite::create(StringUtils::format("Stage3/stage3_%d.png", i + 1));
		Stage3[i]->setAnchorPoint(Vec2(0, 0));
		Stage3[i]->setScale(0.9f);
		Stage3[i]->setPosition(Vec2(2600 + (330 * i), 220 + -(20 * i)));
		AllCp->addChild(Stage3[i], 1);
	}
	/////

	////챕터4
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
		   SelectDress[i]->setPosition(Vec2(600 + (130 * i), 500 ));
		else
		   SelectDress[i]->setPosition(Vec2(-50 + (130 * i), 380));
	
		DressAll->addChild(SelectDress[i], 4);
	}
	AccAll = Sprite::create();
	this->addChild(AccAll, 4);
	for (int i = 0; i < 10; i++)
	{
		SelectAcc[i] = Sprite::create("1.png");
		if (i<5)
			SelectAcc[i]->setPosition(Vec2(600 + (130 * i), 500));
		else
			SelectAcc[i]->setPosition(Vec2(-50 + (130 * i), 380));
		
		AccAll->addChild(SelectAcc[i], 4);
	}
	

	StartStage = Sprite::create("StartStage.png");
	StartStage->setAnchorPoint(Vec2(0.5, 0.5));
	StartStage->setPosition(Vec2(500, 300));
	StartStage->setVisible(false);
	this->addChild(StartStage, 3);
	
	X = Sprite::create("X.png");
	X->setPosition(Vec2(230,450));
	X->setVisible(false);
	this->addChild(X, 3);

	

	All->setVisible(false);
	DressAll->setVisible(false);
	AccAll->setVisible(false);

	RtArrow = Sprite::create("RightArrow.png");
	RtArrow->setPosition(Vec2(750, 70));
	this->addChild(RtArrow, 1);

	LtArrow = Sprite::create("LeftArrow.png");
	LtArrow->setPosition(Vec2(250, 70));
	this->addChild(LtArrow, 1);

	this->setTouchEnabled(true); // 터치활성화 false는 비활성화
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE); // 단일터치

	
	AllCp->setPosition(Vec2(point::get()->ScreenX, 0));
	CCLOG("Screen X = %d", point::get()->ScreenX);
	
	visibleBg = Sprite::create("visibleBg.png");
	visibleBg->setAnchorPoint(Vec2(0, 0));
	visibleBg->setPosition(Vec2(0, 0));
	visibleBg->setOpacity(120);
	visibleBg->setVisible(false);
	this->addChild(visibleBg, 2);
	
	scheduleUpdate();

	return true;
}

void New::menuCallback(cocos2d::Ref * pSender)
{
	if (bisClick != true)
	{
		SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
		Scene *pScene = Chapter::ChapterScene();
		Director::getInstance()->replaceScene(pScene);
	}
}

bool New::onTouchBegan(Touch* touch, Event* _event)
{

	auto point = touch->getLocation();//클릭좌표얻기

	CCLOG("%f %f", point.x, point.y);

	Sex = 0;
	Sex2 = 0;
	if (Closet != nullptr || Shop != nullptr || Closebt != nullptr|| OptionBt !=nullptr|| OptionBack!=nullptr||VolumeUp!=nullptr||RtArrow!=nullptr||LtArrow!=nullptr)
	{

		if (Closet->getBoundingBox().containsPoint(touch->getLocation())&&bisClick!=true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet2.png"));
			Closet->setScale(0.9f);
			closetClick = true;
			Sex = 1;
		}
		if (Shop->getBoundingBox().containsPoint(touch->getLocation())&&bisClick!=true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop2.png"));
			Shop->setScale(0.9f);
			Sex = 2;
		}
		if (Closebt->getBoundingBox().containsPoint(touch->getLocation()))
		{
			closetClick = false;
			All->setVisible(false);
			bisClick = false;
			DressAll->setVisible(false);
			AccAll->setVisible(false);
			visibleBg->setVisible(false);
		}
		if (OptionBt->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			OptionClick = true;
			OptionBt ->setTexture(Director::getInstance()->getTextureCache()->addImage("1.png"));
		}
		if (OptionBack->getBoundingBox().containsPoint(touch->getLocation()))
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
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
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow2.png"));
			RtArrow->setScale(1.2f);
			Sex2 = 1;
			
		}
		if (LtArrow->getBoundingBox().containsPoint(touch->getLocation()) && bisClick != true)
		{
			SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
			LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow2.png"));
			LtArrow->setScale(1.2f);
			Sex2 = 2;
		}
	}
	if (X->getBoundingBox().containsPoint(touch->getLocation())&&bisClick ==true)
	{
		bisClick = false;
		StageClick2 = true;
		X->setVisible(false);
		//StartStage->setVisible(false);
	}
	for (int i = 0; i < 2; i++)
	{
		if (Bt1[i] != nullptr&&closetClick == true)
		{
			if (Bt1[0]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				Dress->setZOrder(5);
				Accessory->setZOrder(4);
				DressAll->setVisible(true);
				AccAll->setVisible(false);
			}
			if (Bt1[1]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				Dress->setZOrder(4);
				Accessory->setZOrder(5);
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
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
				sexClick1 = true;
			}
			if (SelectAcc[i]->getBoundingBox().containsPoint(touch->getLocation())&&point::get()->AbleAcc[i] ==true)
			{
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				ClickNum = i;
				sexClick2 = true;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (Stage[i] != nullptr&& bisClick != true&&StageClick2==false)
		{
			if (Stage[i]->getBoundingBox().containsPoint(touch->getLocation()))
			{
				CCLOG("SDDS");
				SimpleAudioEngine::getInstance()->playEffect("BtClick.wav");
				StartStage->setVisible(true);
				bisClick = true;
				StageClick = true;
				StageNum = i;
			}
		} 
	}
	
	

		return true;
}


void New::onTouchMoved(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();//클릭좌표얻기
	if (sexClick1 == true)
	{
		SelectDress[ClickNum]->setZOrder(6);
		SelectDress[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
	if (sexClick2 == true)
	{
		SelectAcc[ClickNum]->setZOrder(6);
		SelectAcc[ClickNum]->setPosition(Vec2(point.x, point.y));
	}
}

void New::onTouchEnded(Touch* touch, Event* _event)
{
	auto point = touch->getLocation();
	//// 씬전환
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
				SelectDress[i]->setPosition(Vec2(600 + (130 * i), 500));
			else
				SelectDress[i]->setPosition(Vec2(-50 + (130 * i), 380));
		}
		sexClick1 = false;
	}
	if (sexClick2 == true)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i<5)
				SelectAcc[i]->setPosition(Vec2(600 + (130 * i), 500));
			else
				SelectAcc[i]->setPosition(Vec2(-50 + (130 * i), 380));
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
				//StartStage->setVisible(true);
				CCLOG("stage %d", i+1);
			}
		}
			///////StageClick = false;
			StageNum = -1;
	}
	BtEnded();
}
void New::MenuClick(int Clicknum)
{
	
		if (Clicknum == 1) // 옷장 클릭
		{
			bisClick = true;
			visibleBg->setVisible(true);
			DressAll->setVisible(true);
			All->setVisible(true);
			DressOn();
		}
		else if (Clicknum == 2) // 상점 클릭 
		{
			//// 씬전환
			
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

void New::BtEnded()
{

	Closet->setTexture(Director::getInstance()->getTextureCache()->addImage("Closet.png"));
	Shop->setTexture(Director::getInstance()->getTextureCache()->addImage("Shop.png"));
	RtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("RightArrow.png"));
	LtArrow->setTexture(Director::getInstance()->getTextureCache()->addImage("LeftArrow.png"));
	Closet->setScale(0.7f);
	Shop->setScale(0.7f);
	RtArrow->setScale(1.0f);
	LtArrow->setScale(1.0f);
}

void New::update(float dt)
{
	static float t1 = 0;
	static float t2 = 0;
	static float a = 0.0;
	static float b = 1.0;
	t1 += dt;
	t2 += dt;

	if (t1 > 0.01&&StageClick)
	{
		CCLOG("%f", t1);
		a += 0.05;
		StartStage->setScale(a);
		if (a >1.0)
		{
			X->setVisible(true);
			StageClick = false;
		}
		t1 = 0;
	}

	if (t2 > 0.01 && StageClick2)
	{
		a -= 0.05;
		StartStage->setScale(a);
		if (a < 0.0)
		{
			StageClick2 = false;
			StageClick = false;
		}
		t2 = 0;
	}
}