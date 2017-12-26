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

	//设置倒计时默认60
	ScheduleCountDown* countDown = ScheduleCountDown::create(this);

	//设置显示内容，字体，字体大小
	_scheduleLabel = CCLabelTTF::create("60", "Thonburi", 55);
	_scheduleLabel->addChild(countDown);
	this->addChild(_scheduleLabel);
	_scheduleLabel->setPosition(ccp(500, 20));

	CCMenuItemSprite* pause = CCMenuItemSprite::create(CCSprite::create("button_other_003-ipadhd.png"), 
							CCSprite::create("button_other_004-ipadhd.png"),
							this, menu_selector(PanelLayer::pause));

	CCMenu* menu = CCMenu::create(pause, NULL);
	this->addChild(menu);

	CCSize pauseSize = pause->getContentSize();
	menu->setPosition(CCPointMake(winSize.width-pauseSize.width*0.5, pauseSize.height*0.5));

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
