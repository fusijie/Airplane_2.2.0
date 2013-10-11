#include "GameScene.h"

GameScene::GameScene(void)
{
	_gameLayer=NULL;
}

GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		_gameLayer=GameLayer::create();
		CC_BREAK_IF(!_gameLayer);
		this->addChild(_gameLayer);
		bRet=true;
	} while (0);

	return bRet;
}