#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class MutiBulletsLayer :
	public CCLayer
{
public:
	MutiBulletsLayer(void);

	~MutiBulletsLayer(void);

	CREATE_FUNC(MutiBulletsLayer);

	virtual bool init();

	void AddMutiBullets(float dt);

	void mutiBulletsMoveFinished(CCNode* pSender);

	void RemoveMutiBullets(CCSprite* mutiBullets);

	void StartShoot();

	void StopShoot();

public:

	CCArray* m_pAllMutiBullets;

	//CCSpriteFrame* mutiBulletsSpriteFrame;

	CCSpriteBatchNode* mutiBullesBatchNode;
};
