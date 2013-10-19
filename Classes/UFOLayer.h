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

USING_NS_CC;

class UFOLayer :
	public CCLayer
{
public:

	UFOLayer(void);
	
	~UFOLayer(void);

	virtual bool init();

	CREATE_FUNC(UFOLayer);

	void AddMutiBullets(float dt);

	void mutiBulletsMoveFinished(CCNode* pSender);

	void AddBigBoom(float dt);

	void bigBoomMoveFinished(CCNode* pSender);

	void RemoveMutiBullets(CCSprite* mutiBullets);

	void RemoveBigBoom(CCSprite* bigBoom);

public:

	CCArray* m_pAllMutiBullets;

	CCArray* m_pAllBigBoom;

};


