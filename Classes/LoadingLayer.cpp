#include "LoadingLayer.h"
#include "GameScene.h"
#include "PersonalAudioEngine.h"
#include "FishingJoyData.h"

LoadingLayer::LoadingLayer(void)
{
	_loadedSp = 0;
	
	//����3��ͼƬ
	_numSp = 3;

	_progressBar = NULL;

	_progressFg = NULL;
}

CCScene* LoadingLayer::scene(void)
{
	CCScene* scene = CCScene::create();
	LoadingLayer* loadingLayer = LoadingLayer::create();
	scene->addChild(loadingLayer);
	return scene;
}


bool LoadingLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//���ñ�����λ������
	CCSprite* background = CCSprite::create("loading_1-ipadhd.png");
	background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.6));
	this->addChild(background);

	this->initProgressBar();

	this->scheduleOnce(schedule_selector(LoadingLayer::cacheInit), 0.5f);

	return true;
}


void LoadingLayer::initProgressBar()
{
	CCSprite* progressBg = CCSprite::create("loading_4-ipadhd.png");
	_progressFg = CCLabelTTF::create("0/100", "Thonburi", 60);
	//����RGB��ɫ����������Ϊ�ػ�ɫ
	_progressFg->setColor(ccc3(197, 118, 20));

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_progressBar = ProgressBar::create(this, CCSprite::create("loading_5-ipadhd.png"));
	
	//���ñ���
	_progressBar->setBackground(progressBg);

	//����ǰ��
	_progressBar->setForeground(_progressFg);

	//����λ��
	_progressBar->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.25));
	
	//�����ٶ�
	_progressBar->setSpeed(20.0f);

	this->addChild(_progressBar);
}

void LoadingLayer::progressPercentageSetter(float percentage)
{
	CCString* str = CCString::createWithFormat("%d/100", (int)percentage);
	
	//�����ָ��µ���ǩ��, ���������ֻ���Ž��������
	_progressFg->setString(str->getCString());
}

void LoadingLayer::loadingFinished()
{
	CCScene* gameScene = GameScene::create();
	
	CCDirector::sharedDirector()->replaceScene(gameScene);
}

void LoadingLayer::cacheInit(float delta)
{
	CCSpriteFrameCache* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

	//�ܹ���Ҫ����33��
	int progressStart = 1;

	//����
	float ratio = 3.3f;

	//�޸�����plist�ļ��� ɾ��key�е����ģ� ����spriteFrameByName�����޷��ҵ�Frame��������NULL
	//���磺//�޸�metadata->realTextureFileName->FishActor-Large-ipadhdhd.png, textureFileName->FishActor-Large-ipadhd.png
	char fishPlists[][50] = { "FishActor-Large-ipadhd.plist", "FishActor-Marlin-ipadhd.plist", 
		"FishActor-Shark-ipadhd.plist", "FishActor-Small-ipadhd.plist", "FishActor-Mid-ipadhd.plist", 
		"cannon-ipadhd.plist", "Item-chaojiwuqi-ipadhd.plist"};

	for (int i = 0; i < 7; i++)
	{
		spriteFrameCache->addSpriteFramesWithFile(fishPlists[i]);
		//����������
		_progressBar->progressTo(ratio*(progressStart++));
	}

	CCTextureCache* textureCache = CCTextureCache::sharedTextureCache();

	char buttonTextures[][50] = { "ui_button_63-ipadhd.png", "ui_button_65-ipadhd.png",
		"ui_button_music_1-ipadhd.png", "ui_button_music_2-ipadhd.png", "button_other_001-ipadhd.png",
		"button_other_002-ipadhd.png", "button_other_003-ipadhd.png", "button_other_004-ipadhd.png"
	};

	//�������
	for (int i = 0; i < 8; i++)
	{
		textureCache->addImage(buttonTextures[i]);
		_progressBar->progressTo(ratio*(progressStart++));
	}

	char str[][50] = { "SmallFish", "Croaker", "AngelFish", "Amphiprion", "PufferS", 
		"Bream", "Porgy", "Chelonian", "Lantern", "Ray", "Shark", "GoldenTrout", "GShark", 
		"GMarlinsFish", "GrouperFish", "JadePerch", "MarlinsFish", "PufferB" };
	for (int i = 0; i < 18; i++)
	{
		CCArray* array = CCArray::createWithCapacity(10);
		for (int j = 0; j < 10; j++)
		{
			CCString* spriteFrameName = CCString::createWithFormat("%s_actor_%03d.png", str[i], j + 1);
			CCSpriteFrame* spriteFrame = spriteFrameCache->spriteFrameByName(spriteFrameName->getCString());
			CC_BREAK_IF(!spriteFrame);
			array->addObject(spriteFrame);
		}
		if (array->count() == 0)
		{
			continue;
		}
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(array, 0.15f);
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", i + 1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation, animationName->getCString());
		_progressBar->progressTo(ratio*(progressStart++));
	}

	PersonalAudioEngine::sharedEngine();
	FishingJoyData::sharedFishingJoyData();

	_progressBar->progressTo(100.0f);
}
