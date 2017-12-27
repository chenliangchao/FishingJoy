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
	
	//�Ƿ�����������
	void setBackgroundMusic(bool isOn);
	
	//�Ƿ�����Ч
	//void setEffects(bool isOn);

	void playEffects(EffectType type);

	void purge();

	CC_SYNTHESIZE(unsigned int, _bgMusicId, BgMusicId);
	CC_SYNTHESIZE(unsigned int, _netSoundId, NetSoundId);
	CC_SYNTHESIZE(unsigned int, _fireSoundId, FireSoundId);
	CC_SYNTHESIZE(unsigned int, _btnSoundId, BtnSoundId);

};
