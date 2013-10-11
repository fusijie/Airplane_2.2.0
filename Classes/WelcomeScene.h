#pragma once

#include "cocos2d.h"
#include "WelcomeLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class WelcomeScene :
	public CCScene
{
public:
	WelcomeScene(void);

	~WelcomeScene(void);

	virtual bool init();

	CREATE_FUNC(WelcomeScene);

	void PreloadMusic();

public:
	WelcomeLayer* _welcomeLayer;
};
