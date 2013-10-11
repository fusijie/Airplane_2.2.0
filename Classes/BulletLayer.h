#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class BulletLayer :
	public CCLayer
{
public:

	BulletLayer(void);

	~BulletLayer(void);

	CREATE_FUNC(BulletLayer);

	virtual bool init();

	void AddBullet(float dt);

	void bulletMoveFinished(CCNode* pSender);

	void RemoveBullet(CCSprite* bullet);

	void StartShoot(float delay=0.0f);

	void StopShoot();
	
public:

	CCArray* m_pAllBullet;

	//CCSpriteFrame* bulletSpriteFrame;

	CCSpriteBatchNode* bulletBatchNode;

};
