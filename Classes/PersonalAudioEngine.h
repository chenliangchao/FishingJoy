#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

/*typedef enum{
	kEffectSwichCannon = 0,
	kEffectShoot,
	kEffectFishNet,
	kEffectCoins
}EffectType;*/

class PersonalAudioEngine :
	public SimpleAudioEngine
{
public:
	PersonalAudioEngine(void);
	~PersonalAudioEngine(void);
	static PersonalAudioEngine* sharedEngine();
	
	bool init();
	
	//调节背景音乐的声音大小
	void setBackgroundMusicVolume(float volume);
	
	//调节音效的大小
	void setEffectsVolume(float volume);
	
	void purge();
	
};
