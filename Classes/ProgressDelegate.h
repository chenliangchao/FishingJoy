#pragma once
class ProgressDelegate
{
public:

	//进度条载入完成后触发的通知事件
	virtual void loadingFinished() = 0;

	//根据设定的速度改变进度条，时间到达后通知使用者
	virtual void progressPercentageSetter(float percentage)=0;
};
