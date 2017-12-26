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
	
	//�����������ľ���
	void progressBy(float delta/*����ֵ*/);

	//�������ƶ�����
	void progressTo(float destination/*Ŀ��ֵ*/);

	//�����������ñ���ͼƬ
	void setBackground(CCNode* bg);

	//�����������ñ���ͼƬ
	void setForeground(CCNode* fg);

	//�����������ڼ���Ҫ���õ�Э����
	CC_SYNTHESIZE(ProgressDelegate*, _target, Target);

	//������ÿ��Ľ���
	CC_SYNTHESIZE(float, _speed, Speed);

protected:

	//�������ı���ͼƬ
	CCNode* _background;

	//����������ʾ������
	CCNode* _foreground;

	void updatePercentage();

	void loadingFinished();
};
