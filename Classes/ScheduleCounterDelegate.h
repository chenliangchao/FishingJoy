#pragma once
class ScheduleCounterDelegate
{
public:

	//����ʱʱ�䵽��ʱ����Ҫ��ɵĲ���
	virtual void scheduleTimeUp() = 0;

	//����ʱ�����б仯�������
	virtual void setScheduleNumber(int number){
		return;
	}
};
