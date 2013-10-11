#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Enemy :
	public CCNode
{
public:
	Enemy(void);
	~Enemy(void);
	static Enemy* create();
	void bindSprite(CCSprite* sprite,int life);
	CCSprite* getSprite();
	int getLife();
	void loseLife();
	CCRect getBoundingBox();

private:
	CCSprite* m_sprite;
	int m_life;
};
