#pragma once
#include "cocos2d.h"



class FishingJoyData :
	public cocos2d::CCObject
{
public:
	static FishingJoyData* sharedFishingJoyData();

	FishingJoyData();
	~FishingJoyData();

	void reset();

	void flush();
	
	//getxxx/setxxx
	CC_SYNTHESIZE(int, _gold, Gold);
	CC_SYNTHESIZE(bool, _isBeginer, IsBeginer);
	CC_SYNTHESIZE(float, _musicVolume, MusicVolume);
	CC_SYNTHESIZE(float, _soundVolume, SoundVolume);

	void alterGold(int golds);

	void purge();

protected:
	bool init();

};

