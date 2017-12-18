#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"

USING_NS_CC;  // == using namespace cocos2d


class New :public Layer
{
public:
	static Scene* NewScene();

	virtual bool init();

	virtual bool onTouchBegan(Touch* touch, Event*_event);
	virtual void onTouchMoved(Touch* touch, Event*_event);
	virtual void onTouchEnded(Touch* touch, Event*_event); 
	virtual void update(float dt);
	void menuCallback(cocos2d::Ref* Psender);
	void MenuClick(int Clicknum);
	void DressOn();
	void ScreenMove(int Num);
	void BtEnded();

	Sprite *Closet;
	Sprite * Shop;
	Sprite * Alice1;
	Sprite * PopUp;
	///Chapter1
	Sprite *AllCp;
	Sprite * BackGround1;
	Sprite * Stage[4];
	
	Sprite *  starone;
	Sprite *  startwo;
	Sprite *  starthree;
	Sprite *  starfour;

	////
	/// Chapter2
	Sprite * BackGround2;
	
	Sprite * Stage2[4];

	Sprite *  starone2;
	Sprite *  startwo2;
	Sprite *  starthree2;
	Sprite *  starfour2;

	//////
	///// chapter 3
	Sprite * BackGround3;

	Sprite * Stage3[4];

	Sprite *  starone3;
	Sprite *  startwo3;
	Sprite *  starthree3;
	Sprite *  starfour3;


	/////
	
	Sprite * BackGround4;
	Sprite * OptionAll;
	Sprite * OptionBt;
	Sprite * OptionPop;
	Sprite * OptionBack;
	Sprite * VolumeUp;
	Sprite * VolumeDown;
	Sprite * Coin;
	Sprite * LtArrow;
	Sprite * RtArrow;

	int Sex;
	int Sex2;
	float VolumeNum;
	bool bisClick;
	bool OptionClick;
	bool StageClick;
	bool StageClick2;
	int StageNum;
	int ClickNum;
	int Screen;
	bool sexClick1;
	bool sexClick2;
	bool ArrowClick;
	bool closetClick;
	Sprite *Closebt;
	Sprite *All;
	Sprite *Bt1[2];
	Sprite * StartStage;
	Sprite *Dress;
	Sprite * Accessory;
	Sprite * X;
	Sprite * SelectDress[10];
	Sprite * DressAll;

	Sprite *SelectAcc[10];
	Sprite * AccAll;
	Sprite *visibleBg;

	CREATE_FUNC(New);

};