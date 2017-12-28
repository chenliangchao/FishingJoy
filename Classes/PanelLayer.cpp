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

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameMenuLayer-ipadhd.plist");

	_steeringSprite = CCSprite::createWithSpriteFrameName("ui_duo_img.png");
	CCSize steeringSprite = _steeringSprite->getContentSize();
	this->addChild(_steeringSprite);
	_steeringSprite->setPosition(ccp(steeringSprite.width/2, steeringSprite.height/2));

	_rightPanel = CCSprite::createWithSpriteFrameName("ui_box_02.png");
	CCSize rightPanel = _rightPanel->getContentSize();

	this->addChild(_rightPanel);

	_rightPanel->setPosition(ccp(rightPanel.width - steeringSprite.width - 10, rightPanel.height/2));

	_goldCounter = GoldCounterLayer::create(0);
	this->addChild(_goldCounter);
	_goldCounter->setPosition(ccp(572, 43));

	//设置倒计时默认60
	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	//设置显示内容，字体，字体大小
	_scheduleLabel = CCLabelTTF::create("65", "Thonburi", 100);
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(200, winSize.height - 100));

	//创建暂停按钮
	CCSprite* stopSprite = CCSprite::createWithSpriteFrameName("ui_button_02.png");

	CCMenuItemSprite* pause = CCMenuItemSprite::create(stopSprite, 
		stopSprite,
		this, menu_selector(PanelLayer::pause));

	_menu = CCMenu::create(pause, NULL);
	this->addChild(_menu);


	CCSize pauseSize = pause->getContentSize();

	pause->setContentSize(pause->getContentSize()*2);
	_menu->setPosition(ccp(winSize.width-pauseSize.width*2, winSize.height - pauseSize.height/2));

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
	//先把_scheduleLabel隐藏
	_scheduleLabel->setVisible(false);

	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->scheduleTimeUp();
}
