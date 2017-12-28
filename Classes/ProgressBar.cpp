#include "ProgressBar.h"

enum{
	k_Progress_Action = 0
};

ProgressBar* ProgressBar::create(ProgressDelegate* target, CCSprite *sprite)
{
	ProgressBar* pg = new ProgressBar();
	pg->autorelease();
	pg->init(target, sprite);
	return pg;
}

bool ProgressBar::init(ProgressDelegate* target, CCSprite *sprite)
{
	CCProgressTimer::initWithSprite(sprite);
	this->setTarget(target);

	//将进度条设置为条状
	this->setType(kCCProgressTimerTypeBar);

	//设置起始位置
	this->setMidpoint(ccp(0, 0.5));

	//设置进度条速度
	this->setSpeed(1.0f);

	//设置结束位置
	this->setBarChangeRate(ccp(1, 0));

	return true;
}

void ProgressBar::progressBy(float delta/*滚动的百分比*/)
{
	//进度条末尾
	float maxPercentage = 100.0f;

	bool isFinished = false;

	float nextPercentage = delta + this->getPercentage();

	if(nextPercentage >= maxPercentage){
		nextPercentage = maxPercentage;
		isFinished = true;
	}

	//停止之前未完成的进度条滚动事件
	//this->stopActionByTag(k_Progress_Action);

	//执行的动作
	CCArray* actions = CCArray::createWithCapacity(2);

	//间隔时间
	float duration = delta/this->getSpeed();

	//进度条移动的动作
	CCProgressTo* to = CCProgressTo::create(duration, nextPercentage);
	actions->addObject(to);

	if(isFinished){

		//结束后要执行的操作
		CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(ProgressBar::loadingFinished));
		actions->addObject(callfunc);
	}

	CCSequence* seq = CCSequence::create(actions);

	//进度条进度改变时的回调函数
	CCCallFunc* updateCallFunc = CCCallFunc::create(this, callfunc_selector(ProgressBar::updatePercentage));
	
	updateCallFunc->setDuration(duration);

	CCSpawn* spawn = CCSpawn::createWithTwoActions(seq, updateCallFunc);
	spawn->setTag(k_Progress_Action);

	this->runAction(spawn);
}

void ProgressBar::setBackground(CCNode* bg)
{
	//将旧背景删除
	this->removeChild(_background,true);
	_background = bg;

	//获取进度条图片的大小
	CCSize size = this->getSprite()->getContentSize();

	//设置背景位置
	_background->setPosition(ccp(size.width*0.5, size.height*0.46));

	//将背景加入本节点中
	this->addChild(_background, -1);
}

void ProgressBar::setForeground(CCNode* fg)
{	
	this->removeChild(_foreground,true);
	_foreground = fg;

	CCSize size = this->getSprite()->getContentSize();

	_foreground->setPosition(ccp(size.width*0.5, size.height*0.5));

	//设置为1，字体显示在背景之前
	this->addChild(_foreground, 1);
}

void ProgressBar::updatePercentage()
{
	_target->progressPercentageSetter(this->getPercentage());
}

void ProgressBar::loadingFinished()
{
	_target->loadingFinished();
}

void ProgressBar::progressTo(float destination)
{
	float delta = destination-this->getPercentage();
	this->progressBy(delta);
}
