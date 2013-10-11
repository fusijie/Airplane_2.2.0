#include "UFOLayer.h"

UFOLayer::UFOLayer(void)
{
	m_pAllMutiBullets=CCArray::create();
	m_pAllMutiBullets->retain();
	m_pAllBigBoom=CCArray::create();
	m_pAllBigBoom->retain();
}

UFOLayer::~UFOLayer(void)
{
	m_pAllMutiBullets->release();
	m_pAllMutiBullets=NULL;
	m_pAllBigBoom->release();
	m_pAllBigBoom=NULL;
}

bool UFOLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		this->schedule(schedule_selector(UFOLayer::AddMutiBullets),20.0);
		this->schedule(schedule_selector(UFOLayer::AddBigBoom),20.0,kCCRepeatForever,5.0);
		bRet=true;
	} while (0);

	return bRet;
}

void UFOLayer::AddMutiBullets(float dt)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/out_porp.mp3");
	CCSprite* mutiBullets=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ufo1.png"));

	CCSize mutiBlletsSize=mutiBullets->getContentSize();
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	int minX=mutiBlletsSize.width/2;
	int maxX=winSize.width-mutiBlletsSize.width/2;
	int rangeX=maxX-minX;
	int actualX=(rand()%rangeX)+minX;

	mutiBullets->setPosition(ccp(actualX,winSize.height+mutiBlletsSize.height/2));
	this->addChild(mutiBullets);
	this->m_pAllMutiBullets->addObject(mutiBullets);

	CCMoveBy* move1 = CCMoveBy::create(0.5f, CCPointMake(0, -150));
	CCMoveBy* move2 = CCMoveBy::create(0.3f, CCPointMake(0, 100));
	CCMoveBy* move3 = CCMoveBy::create(1.0f, CCPointMake(0,0-winSize.height-mutiBlletsSize.height/2));
	CCCallFuncN* moveDone = CCCallFuncN::create(this,callfuncN_selector(UFOLayer::mutiBulletsMoveFinished));

	CCFiniteTimeAction* sequence = CCSequence::create(move1,move2,move3,moveDone,NULL);
	mutiBullets->runAction(sequence);

}

void UFOLayer::mutiBulletsMoveFinished(CCNode* pSender)
{
	CCSprite* mutiBullets=(CCSprite*)pSender;
	this->removeChild(mutiBullets,true);//从屏幕中移除
	this->m_pAllMutiBullets->removeObject(mutiBullets);//从数组中移除
}

void UFOLayer::AddBigBoom(float dt)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/out_porp.mp3");
	CCSprite* bigBoom=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ufo2.png"));

	CCSize bigBoomSize=bigBoom->getContentSize();
	CCSize winSize=CCDirector::sharedDirector()->getWinSize();
	int minX=bigBoomSize.width/2;
	int maxX=winSize.width-bigBoomSize.width/2;
	int rangeX=maxX-minX;
	int actualX=(rand()%rangeX)+minX;

	bigBoom->setPosition(ccp(actualX,winSize.height+bigBoomSize.height/2));
	this->addChild(bigBoom);
	this->m_pAllBigBoom->addObject(bigBoom);

	CCMoveBy* move1 = CCMoveBy::create(0.5, CCPointMake(0, -150));
	CCMoveBy* move2 = CCMoveBy::create(0.3, CCPointMake(0, 100));
	CCMoveBy* move3 = CCMoveBy::create(1.0, CCPointMake(0,0-winSize.height-bigBoomSize.height/2));
	CCCallFuncN* moveDone = CCCallFuncN::create(this,callfuncN_selector(UFOLayer::bigBoomMoveFinished));

	CCFiniteTimeAction* sequence = CCSequence::create(move1,move2,move3,moveDone,NULL);
	bigBoom->runAction(sequence);
}

void UFOLayer::bigBoomMoveFinished(CCNode* pSender)
{
	CCSprite* bigBoom=(CCSprite*)pSender;
	this->removeChild(bigBoom,true);
	this->m_pAllBigBoom->removeObject(bigBoom);
}

void UFOLayer::RemoveMutiBullets(CCSprite* mutiBullets)
{
	this->removeChild(mutiBullets,true);
	this->m_pAllMutiBullets->removeObject(mutiBullets);
}

void UFOLayer::RemoveBigBoom(CCSprite* bigBoom)
{
	this->removeChild(bigBoom,true);
	this->m_pAllBigBoom->removeObject(bigBoom);
}