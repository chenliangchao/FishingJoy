#include "ScheduleCountDown.h"

ScheduleCountDown* ScheduleCountDown::create(ScheduleCounterDelegate* target, int perimeter, bool loop)
{
	ScheduleCountDown* counter = new ScheduleCountDown();
	counter->init(target, perimeter, loop);
	counter->autorelease();
	return counter;
}

bool ScheduleCountDown::init(ScheduleCounterDelegate* target, int perimeter, bool loop)
{
	_target = target;
	_maxTime = perimeter;
	_currTime = perimeter;
	_loop = loop;
	
	//注册间隔1.0秒要调用的函数
	this->schedule(schedule_selector(ScheduleCountDown::schedulePerSecond), 1.0f);
	return true;
}


void ScheduleCountDown::schedulePerSecond(float delta)
{
	_currTime--;

	if(_currTime <= 0){
		bool isLoop = this->getLoop();
		if(isLoop){
			//重新开始倒计时
			_currTime = _maxTime;
		}else{
			//删除计时器
			this->unschedule(schedule_selector(ScheduleCountDown::schedulePerSecond));
		}
		//通知协议类计时周期结束
		_target->scheduleTimeUp();
	}
	//将当前的倒计时情况通知给协议对象
	_target->setScheduleNumber(_currTime);
}
