#pragma once

#include "cocos2d.h"
#include "GameLayer.h"

USING_NS_CC;

class GameScene :
	public CCScene
{
public:
	
	GameScene(void);

	~GameScene(void);

	CREATE_FUNC(GameScene);

	virtual bool init();

	GameLayer* _gameLayer;


};
