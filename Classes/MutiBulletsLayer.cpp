#include "MutiBulletsLayer.h"
#include "PlaneLayer.h"

MutiBulletsLayer::MutiBulletsLayer(void)
{
	//mutiBulletsSpriteFrame=NULL;
	mutiBullesBatchNode=NULL;

	m_pAllMutiBullets=CCArray::create();
	m_pAllMutiBullets->retain();
}

MutiBulletsLayer::~MutiBulletsLayer(void)
{
	m_pAllMutiBullets->release();
	m_pAllMutiBullets=NULL;
}

bool MutiBulletsLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		//mutiBulletsSpriteFrame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("bullet2.png");

		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("ui/shoot.png");
		mutiBullesBatchNode = CCSpriteBatchNode::createWithTexture(texture);
		this->addChild(mutiBullesBatchNode);

		bRet=true;
	} while (0);
	return bRet;
}

void MutiBulletsLayer::StartShoot()
{
	this->schedule(schedule_selector(MutiBulletsLayer::AddMutiBullets),0.2f,30,0.0f);
}

void MutiBulletsLayer::StopShoot()
{
	this->unschedule(schedule_selector(MutiBulletsLayer::AddMutiBullets));
}

void MutiBulletsLayer::AddMutiBullets(float dt)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/bullet.mp3");

	CCSprite* bulletLeft=CCSprite::createWithSpriteFrameName("bullet2.png");
	CCSprite* bulletRight=CCSprite::createWithSpriteFrameName("bullet2.png");
	mutiBullesBatchNode->addChild(bulletLeft);
	mutiBullesBatchNode->addChild(bulletRight);
	this->m_pAllMutiBullets->addObject(bulletLeft);
	this->m_pAllMutiBullets->addObject(bulletRight);

	CCPoint planePosition=PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	CCPoint bulletLeftPosition=ccp(planePosition.x-33,planePosition.y+35);
	CCPoint bulletRightPosition=ccp(planePosition.x+33,planePosition.y+35);
	bulletLeft->setPosition(bulletLeftPosition);
	bulletRight->setPosition(bulletRightPosition);

	float length=CCDirector::sharedDirector()->getWinSize().height+bulletLeft->getContentSize().height/2-bulletLeftPosition.y;
	float velocity=420/1;//420pixel/sec
	float realMoveDuration=length/velocity;

	CCFiniteTimeAction* actionLeftMove=CCMoveTo::create(realMoveDuration,ccp(bulletLeftPosition.x,CCDirector::sharedDirector()->getWinSize().height+bulletLeft->getContentSize().height/2));
	CCFiniteTimeAction* actionLeftDone=CCCallFuncN::create(this,callfuncN_selector(MutiBulletsLayer::mutiBulletsMoveFinished));
	CCSequence* sequenceLeft=CCSequence::create(actionLeftMove,actionLeftDone,NULL);
	
	CCFiniteTimeAction* actionRightMove=CCMoveTo::create(realMoveDuration,ccp(bulletRightPosition.x,CCDirector::sharedDirector()->getWinSize().height+bulletRight->getContentSize().height/2));
	CCFiniteTimeAction* actionRightDone=CCCallFuncN::create(this,callfuncN_selector(MutiBulletsLayer::mutiBulletsMoveFinished));
	CCSequence* sequenceRight=CCSequence::create(actionRightMove,actionRightDone,NULL);

	bulletLeft->runAction(sequenceLeft);
	bulletRight->runAction(sequenceRight);
}

void MutiBulletsLayer::mutiBulletsMoveFinished(CCNode* pSender)
{
	CCSprite* mutiBullets=(CCSprite*)pSender;
	m_pAllMutiBullets->removeObject(mutiBullets);
	this->mutiBullesBatchNode->removeChild(mutiBullets,true);
	CCLog("MutiBUlletsCount=%d",m_pAllMutiBullets->count());
}

void MutiBulletsLayer::RemoveMutiBullets(CCSprite* mutiBullets)
{
	if (mutiBullets!=NULL)
	{
		this->m_pAllMutiBullets->removeObject(mutiBullets);
		this->mutiBullesBatchNode->removeChild(mutiBullets,true);
	}
}
