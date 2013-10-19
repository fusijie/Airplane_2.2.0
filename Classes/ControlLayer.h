/*******************************************************************************
	Author						: JackyFu
	Email                   	: fusijie@vip.qq.com
	QQ  						: 754505629
	Blog						: http://blog.csdn.net/jackystudio
	All Rights Reserved
	
	This piece of code does not have any registered copyright and is free to be 
	used as necessary. The user is free to modify as per the requirements. As a
	fellow developer, all that I expect and request for is to be given the 
	credit for intially developing this reusable code by not removing my name as 
	the author.
*******************************************************************************/
#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "NoTouchLayer.h"

USING_NS_CC;

const int MAX_SCORE=1000000000;

class ControlLayer :
	public CCLayer
{
public:

	ControlLayer(void);

	~ControlLayer(void);

	virtual bool init();

	CREATE_FUNC(ControlLayer);

	void menuPauseCallback(CCObject* pSender);

	void updateScore(int score);

public:

	CCLabelBMFont* scoreItem;

	CCMenuItemImage* pPauseItem;

	NoTouchLayer* noTouchLayer;
};
