#include "PanelLayer.h"
#include "GameScene.h"
#include "ScheduleCountDown.h"

PanelLayer::PanelLayer(void)
{

}

PanelLayer::~PanelLayer(void)
{

}
bool PanelLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	_goldCounter->setPosition(ccp(600, 20));

	//���õ���ʱĬ��60
	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	//������ʾ���ݣ����壬�����С
	_scheduleLabel = CCLabelTTF::create("60", "Thonburi", 55);
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(500, 20));

	//������ͣ��ť
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameMenuLayer-ipadhd.plist");

	CCSprite* stopSprite = CCSprite::createWithSpriteFrameName("ui_button_02.png");

	CCMenuItemSprite* pause = CCMenuItemSprite::create(stopSprite, 
		stopSprite,
		this, menu_selector(PanelLayer::pause));

	_menu = CCMenu::create(pause, NULL);
	this->addChild(_menu);

	CCSize pauseSize = pause->getContentSize();
	_menu->setPosition(CCPointMake(winSize.width-pauseSize.width, winSize.height - pauseSize.height));

    return true;
}

void PanelLayer::pause(CCObject *sender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->pause();
}

void PanelLayer::setScheduleNumber(int number)
{
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp()
{
	//�Ȱ�_scheduleLabel����
	_scheduleLabel->setVisible(false);

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
