#include "FishLayer.h"
#include "Fish.h"

FishLayer::FishLayer(void)
{
}

bool FishLayer::init()
{
	do 
	{
		if (!CCLayer::init())
		{
			return false;
		}
		Fish* fish = Fish::create((FishType)3);
		CC_BREAK_IF(!fish);
		this->addChild(fish);
		fish->setPosition(ccp(1200, 800));
		return true;
	} while (0);
	return false;
}

FishLayer::~FishLayer(void)
{
}
