#pragma once

using namespace std;
#include<iostream>
#include "cocos2d.h"
USING_NS_CC;
class point
{
private:

	static point* a;

public:
	int DressArr[100];
	int AccArr[100];
	bool AbleDress[10];
	bool AbleAcc[10];
	int ScreenX;
	point()
	{
		/*for (int i = 0; i < 10; i++)
		{
			AbleDress[i] = false;
		}*/
		
	}
	static point* get()
	{
		if (a == NULL)
		{
			a = new point();
		}
		return a;
	}
};
