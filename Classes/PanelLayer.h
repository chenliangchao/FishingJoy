#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class PanelLayer
	:public CCLayer, public ScheduleCounterDelegate
{
public:
	virtual bool init();
	PanelLayer(void);
	~PanelLayer(void);

    CREATE_FUNC(PanelLayer)
    CC_SYNTHESIZE_READONLY(GoldCounterLayer *, _goldCounter, GoldCounter);

	CC_SYNTHESIZE_READONLY(CCMenu*, _menu, Menu);

	//�麯��ʵ��
	void scheduleTimeUp();

	//���ᱻScheduleCountDown����
	void setScheduleNumber(int number);

protected:
	void pause(CCObject *sender);

	//CCLabelTTF������ʾ��ǰ�ĵ���ʱʱ��
	CCLabelTTF* _scheduleLabel;

	//���
	CCSprite* _steeringSprite;

	//���
	CCSprite* _rightPanel;
};

