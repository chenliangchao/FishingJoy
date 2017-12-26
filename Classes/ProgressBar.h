#pragma once
#include "cocos2d.h"
#include "ProgressDelegate.h"

USING_NS_CC;

class ProgressBar
	:public CCProgressTimer
{
public:

	static ProgressBar* create(ProgressDelegate* target, CCSprite *sprite);
	bool init(ProgressDelegate* target, CCSprite *sprite);
	
	//进度条滚动的距离
	void progressBy(float delta/*增加值*/);

	//进度条移动结束
	void progressTo(float destination/*目标值*/);

	//给进度条设置背景图片
	void setBackground(CCNode* bg);

	//给进度条设置背景图片
	void setForeground(CCNode* fg);

	//进度条滚动期间需要调用的协议类
	CC_SYNTHESIZE(ProgressDelegate*, _target, Target);

	//进度条每秒的进度
	CC_SYNTHESIZE(float, _speed, Speed);

protected:

	//进度条的背景图片
	CCNode* _background;

	//进度条上显示的内容
	CCNode* _foreground;

	void updatePercentage();

	void loadingFinished();
};
