#include "Enemy.h"

Enemy::Enemy(void)
{
	m_sprite=NULL;
	m_life=0;
}

Enemy::~Enemy(void)
{
}

Enemy* Enemy::create()
{
	Enemy* pRet=new Enemy;
	pRet->autorelease();
	return pRet;
}

void Enemy::bindSprite(CCSprite* sprite,int life)
{
	m_sprite=sprite;
	m_life=life;
	this->addChild(m_sprite);
}

CCSprite* Enemy::getSprite()
{
	return m_sprite;
}

int Enemy::getLife()
{
	return m_life;
}

void Enemy::loseLife()
{
	m_life--;
}

CCRect Enemy::getBoundingBox()
{
	CCRect rect=m_sprite->boundingBox();
	CCPoint pos=this->convertToWorldSpace(rect.origin);
	CCRect enemyRect(pos.x,pos.y,rect.size.width,rect.size.height);
	return enemyRect;
}