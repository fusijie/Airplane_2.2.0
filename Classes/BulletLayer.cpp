#include "BulletLayer.h"
#include "PlaneLayer.h"

BulletLayer::BulletLayer(void)
{
	//bulletSpriteFrame=NULL;
	bulletBatchNode=NULL;

	m_pAllBullet=CCArray::create();
	m_pAllBullet->retain();
}

BulletLayer::~BulletLayer(void)
{
	m_pAllBullet->release();
	m_pAllBullet=NULL;
}

bool BulletLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		//bulletSpriteFrame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("bullet1.png");

		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("ui/shoot.png");
		bulletBatchNode = CCSpriteBatchNode::createWithTexture(texture);
		this->addChild(bulletBatchNode);

		bRet=true;
	} while (0);
	return bRet;
}

void BulletLayer::StartShoot(float delay)
{
	this->schedule(schedule_selector(BulletLayer::AddBullet),0.20f,kCCRepeatForever,delay);
}

void BulletLayer::StopShoot()
{
	this->unschedule(schedule_selector(BulletLayer::AddBullet));
}

void BulletLayer::AddBullet(float dt)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/bullet.mp3");
	CCSprite* bullet=CCSprite::createWithSpriteFrameName("bullet1.png");
	bulletBatchNode->addChild(bullet);
	//this->addChild(bullet);
	this->m_pAllBullet->addObject(bullet);

	CCPoint planePosition=PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
	CCPoint bulletPosition=ccp(planePosition.x,planePosition.y+PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height/2);
	bullet->setPosition(bulletPosition);
    
	float length=CCDirector::sharedDirector()->getWinSize().height+bullet->getContentSize().height/2-bulletPosition.y;
	float velocity=320/1;//320pixel/sec
	float realMoveDuration=length/velocity;

	CCFiniteTimeAction* actionMove=CCMoveTo::create(realMoveDuration,ccp(bulletPosition.x,CCDirector::sharedDirector()->getWinSize().height+bullet->getContentSize().height/2));
	CCFiniteTimeAction* actionDone=CCCallFuncN::create(this,callfuncN_selector(BulletLayer::bulletMoveFinished));

	CCSequence* sequence=CCSequence::create(actionMove,actionDone,NULL);
	bullet->runAction(sequence);
}

void BulletLayer::bulletMoveFinished(CCNode* pSender)
{
	CCSprite* bullet=(CCSprite*)pSender;
	this->bulletBatchNode->removeChild(bullet,true);
	this->m_pAllBullet->removeObject(bullet);
}

void BulletLayer::RemoveBullet(CCSprite* bullet)
{
	if (bullet!=NULL)
	{
		this->bulletBatchNode->removeChild(bullet,true);
		this->m_pAllBullet->removeObject(bullet);
	}
}

