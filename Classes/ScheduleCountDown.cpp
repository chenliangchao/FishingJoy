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
	
	//ע����1.0��Ҫ���õĺ���
	this->schedule(schedule_selector(ScheduleCountDown::schedulePerSecond), 1.0f);
	return true;
}


void ScheduleCountDown::schedulePerSecond(float delta)
{
	_currTime--;

	if(_currTime <= 0){
		bool isLoop = this->getLoop();
		if(isLoop){
			//���¿�ʼ����ʱ
			_currTime = _maxTime;
		}else{
			//ɾ����ʱ��
			this->unschedule(schedule_selector(ScheduleCountDown::schedulePerSecond));
		}
		//֪ͨЭ�����ʱ���ڽ���
		_target->scheduleTimeUp();
	}
	//����ǰ�ĵ���ʱ���֪ͨ��Э�����
	_target->setScheduleNumber(_currTime);
}
