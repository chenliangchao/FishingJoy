#pragma once
#include "cocos2d.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class ScheduleCountDown :
	public CCNode
{
public:
	//��̬��Ա����������ScheduleCountDown����
	static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);

	//���������浽��Ӧ�����ݳ�Ա��
	bool init (ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);

	CC_SYNTHESIZE(bool, _loop, Loop);

protected:
	ScheduleCounterDelegate* _target;
	//��ǰʱ��
	int _currTime;
	//���ʱ��
	int _maxTime;

	//����ʱ��Ҫ������ÿ���1�뱻���õ��ĺ���
	void schedulePerSecond(float delta);
};

