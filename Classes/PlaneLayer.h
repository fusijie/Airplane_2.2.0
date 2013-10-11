#pragma once

#include "cocos2d.h"

USING_NS_CC;

const int AIRPLANE=747;

class PlaneLayer :
	public CCLayer
{
public:

	PlaneLayer(void);
	
	~PlaneLayer(void);

	static PlaneLayer* create();

	virtual bool init();

	void MoveTo(CCPoint location);

	void Blowup(int passScore);

	void RemovePlane();

public:

	static PlaneLayer* sharedPlane;

	bool isAlive;

	int score;
};
