#pragma once
#include "cocos2d.h"
#include "ScheduleCounterDelegate.h"

USING_NS_CC;

class ScheduleCountDown :
	public CCNode
{
public:
	//静态成员函数，创建ScheduleCountDown对象
	static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);

	//将参数保存到相应的数据成员中
	bool init (ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);

	CC_SYNTHESIZE(bool, _loop, Loop);

protected:
	ScheduleCounterDelegate* _target;
	//当前时间
	int _currTime;
	//最大时间
	int _maxTime;

	//倒计时主要函数，每间隔1秒被调用到的函数
	void schedulePerSecond(float delta);
};

