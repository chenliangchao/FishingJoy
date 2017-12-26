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
	
	//���ڱ������ֵ�������С
	void setBackgroundMusicVolume(float volume);
	
	//������Ч�Ĵ�С
	void setEffectsVolume(float volume);
	
	void purge();
	
};
