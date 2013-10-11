#include "NoTouchLayer.h"

bool NoTouchLayer::init(){  
	if (!CCLayer::init() )  
	{  
		return false;  
	}  
	setTouchEnabled(true);  
	return true;  
}  

void NoTouchLayer::registerWithTouchDispatcher()
{  
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -127 , true);
	CCLayer::registerWithTouchDispatcher();  
}  

bool NoTouchLayer::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{     
	return true;  
}  

void NoTouchLayer::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{  
}  

void NoTouchLayer::ccTouchEnded (CCTouch *pTouch, CCEvent *pEvent)
{  
}  