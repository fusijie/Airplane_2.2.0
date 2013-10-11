#include "ControlLayer.h"

ControlLayer::ControlLayer(void)
{
	scoreItem=NULL;
	pPauseItem=NULL;
}

ControlLayer::~ControlLayer(void)
{
}

bool ControlLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		CCSize winSize=CCDirector::sharedDirector()->getWinSize();

		//加入PauseMenu
		CCSprite* normalPause=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_nor.png"));
		CCSprite* pressedPause=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_pressed.png"));
		pPauseItem=CCMenuItemImage::create();
		pPauseItem->initWithNormalSprite(normalPause,pressedPause,NULL,this,menu_selector(ControlLayer::menuPauseCallback));
		pPauseItem->setPosition(ccp(normalPause->getContentSize().width/2+10,winSize.height-normalPause->getContentSize().height/2-10));
		CCMenu *menuPause=CCMenu::create(pPauseItem,NULL);
		menuPause->setPosition(CCPointZero);
		this->addChild(menuPause,101);

		//加入score
		scoreItem=CCLabelBMFont::create("0","font/font.fnt");
		scoreItem->setColor(ccc3(143,146,147));
		scoreItem->setAnchorPoint(ccp(0,0.5));
		scoreItem->setPosition(ccp(pPauseItem->getPositionX()+normalPause->getContentSize().width/2+5,pPauseItem->getPositionY()));
		this->addChild(scoreItem);

		bRet=true;
	} while (0);

	return bRet;
}

void ControlLayer::menuPauseCallback(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/button.mp3");
	if(!CCDirector::sharedDirector()->isPaused())
	{
		pPauseItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_resume_nor.png"));
		pPauseItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_resume_pressed.png"));
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		CocosDenshion::SimpleAudioEngine::sharedEngine()->stopAllEffects();
		CCDirector::sharedDirector()->pause();
		noTouchLayer=NoTouchLayer::create();
		this->addChild(noTouchLayer);
	}
	else
	{
		pPauseItem->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_nor.png"));
		pPauseItem->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_pause_pressed.png"));
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		CCDirector::sharedDirector()->resume();
		this->removeChild(noTouchLayer,true);
	}
}

void ControlLayer::updateScore(int score)
{
	if (score>=0 && score<=MAX_SCORE)
	{
		CCString* strScore=CCString::createWithFormat("%d",score);
		scoreItem->setString(strScore->m_sString.c_str());
	}
}
