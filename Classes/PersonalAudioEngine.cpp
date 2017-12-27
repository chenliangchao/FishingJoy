#include "PersonalAudioEngine.h"
#include "FishingJoyData.h"

PersonalAudioEngine::PersonalAudioEngine(void)
{
}


PersonalAudioEngine::~PersonalAudioEngine(void)
{
}

static PersonalAudioEngine* _sharedEngine = NULL;

PersonalAudioEngine* PersonalAudioEngine::sharedEngine()
{
	if(_sharedEngine==NULL){
		_sharedEngine = new PersonalAudioEngine();
		_sharedEngine->init();
	}
	return _sharedEngine;
}

bool PersonalAudioEngine::init()
{
	this->preloadBackgroundMusic("music_1.mp3");
	this->preloadEffect("bgm_button.aif");
	this->preloadEffect("bgm_fire.aif");
	this->preloadEffect("bgm_net.mp3");

	this->setBackgroundMusic((float)(FishingJoyData::sharedFishingJoyData()->getMusic()));
	//this->setEffects((float)(FishingJoyData::sharedFishingJoyData()->getSound()));

	return true;
}

void PersonalAudioEngine::setBackgroundMusic(bool isOn)
{
	//win32 cocos2d音量大小修改无效
	//this->setBackgroundMusicVolume(isOn);
	if(isOn)
	{
		this->pauseBackgroundMusic();
	}
	else
	{
		this->resumeBackgroundMusic();
	}
	FishingJoyData::sharedFishingJoyData()->setMusic(!isOn);
}

//无法设置音效开关
/*void PersonalAudioEngine::setEffects(bool isOn)
{
	//win32 cocos2d音量大小修改无效
	//this->setEffectsVolume(isOn);
	//暂停所有也无效
	//this->pauseAllEffects();
	
	if(isOn)
	{
		//获取ID号进行暂停
		this->pauseEffect(this->getNetSoundId());
		this->pauseEffect(this->getFireSoundId());
		this->pauseEffect(this->getBtnSoundId());
	}
	else
	{
		this->resumeEffect(this->getNetSoundId());
		this->resumeEffect(this->getFireSoundId());
		this->resumeEffect(this->getBtnSoundId());
	}
	FishingJoyData::sharedFishingJoyData()->setSound(!isOn);
}
*/

void PersonalAudioEngine::purge()
{

}

void PersonalAudioEngine::playEffects(EffectType type)
{
	switch(type)
	{
	case kEffectFishNet:
		//返回一个ID号
		this->setNetSoundId(playEffect("bgm_net.mp3"));
		break;
	case kEffectShoot:
		this->setFireSoundId(playEffect("bgm_fire.aif"));
		break;
	case kEffectSwichCannon:
		this->setBtnSoundId(playEffect("bgm_button.aif"));
		break;
	default:
		break;
	}
}


