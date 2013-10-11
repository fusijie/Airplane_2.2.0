#pragma once
#include "cocos2d.h"
USING_NS_CC;

class NoTouchLayer :
	public CCLayer
{
public:
	virtual bool init();   

	// implement the "static node()" method manually 
	CREATE_FUNC(NoTouchLayer); 

	virtual void registerWithTouchDispatcher(); 

	virtual bool ccTouchBegan (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); 
	virtual void ccTouchMoved (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); 
	virtual void ccTouchEnded (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); 
};
