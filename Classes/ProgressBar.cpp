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

	//������������Ϊ��״
	this->setType(kCCProgressTimerTypeBar);

	//������ʼλ��
	this->setMidpoint(ccp(0, 0.5));

	//���ý������ٶ�
	this->setSpeed(1.0f);

	//���ý���λ��
	this->setBarChangeRate(ccp(1, 0));

	return true;
}

void ProgressBar::progressBy(float delta/*�����İٷֱ�*/)
{
	//������ĩβ
	float maxPercentage = 100.0f;

	bool isFinished = false;

	float nextPercentage = delta + this->getPercentage();

	if(nextPercentage >= maxPercentage){
		nextPercentage = maxPercentage;
		isFinished = true;
	}

	//ֹ֮ͣǰδ��ɵĽ����������¼�
	//this->stopActionByTag(k_Progress_Action);

	//ִ�еĶ���
	CCArray* actions = CCArray::createWithCapacity(2);

	//���ʱ��
	float duration = delta/this->getSpeed();

	//�������ƶ��Ķ���
	CCProgressTo* to = CCProgressTo::create(duration, nextPercentage);
	actions->addObject(to);

	if(isFinished){

		//������Ҫִ�еĲ���
		CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(ProgressBar::loadingFinished));
		actions->addObject(callfunc);
	}

	CCSequence* seq = CCSequence::create(actions);

	//���������ȸı�ʱ�Ļص�����
	CCCallFunc* updateCallFunc = CCCallFunc::create(this, callfunc_selector(ProgressBar::updatePercentage));
	
	updateCallFunc->setDuration(duration);

	CCSpawn* spawn = CCSpawn::createWithTwoActions(seq, updateCallFunc);
	spawn->setTag(k_Progress_Action);

	this->runAction(spawn);
}

void ProgressBar::setBackground(CCNode* bg)
{
	//���ɱ���ɾ��
	this->removeChild(_background,true);
	_background = bg;

	//��ȡ������ͼƬ�Ĵ�С
	CCSize size = this->getSprite()->getContentSize();

	//���ñ���λ��
	_background->setPosition(ccp(size.width*0.5, size.height*0.46));

	//���������뱾�ڵ���
	this->addChild(_background, -1);
}

void ProgressBar::setForeground(CCNode* fg)
{	
	this->removeChild(_foreground,true);
	_foreground = fg;

	CCSize size = this->getSprite()->getContentSize();

	_foreground->setPosition(ccp(size.width*0.5, size.height*0.5));

	//����Ϊ1��������ʾ�ڱ���֮ǰ
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
