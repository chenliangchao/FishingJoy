#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

typedef enum{
	kEffectSwichCannon = 0,
	kEffectShoot,
	kEffectFishNet,
	kEffectCoins
}EffectType;

class PersonalAudioEngine :
	public SimpleAudioEngine
{
public:
	PersonalAudioEngine(void);
	~PersonalAudioEngine(void);
	static PersonalAudioEngine* sharedEngine();
	
	bool init();
	
	//是否开启背景音乐
	void setBackgroundMusic(bool isOn);
	
	//是否开启音效
	//void setEffects(bool isOn);

	void playEffects(EffectType type);

	void purge();

	CC_SYNTHESIZE(unsigned int, _bgMusicId, BgMusicId);
	CC_SYNTHESIZE(unsigned int, _netSoundId, NetSoundId);
	CC_SYNTHESIZE(unsigned int, _fireSoundId, FireSoundId);
	CC_SYNTHESIZE(unsigned int, _btnSoundId, BtnSoundId);

};
