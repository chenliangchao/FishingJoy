#pragma once
class ScheduleCounterDelegate
{
public:

	//倒计时时间到的时候需要完成的操作
	virtual void scheduleTimeUp() = 0;

	//倒计时过程中变化后的数字
	virtual void setScheduleNumber(int number){
		return;
	}
};
