#pragma once
#include "cocos2d.h" 
#include "ProgressDelegate.h"
#include "ProgressBar.h"

USING_NS_CC;

class LoadingLayer :
	public CCLayer, public ProgressDelegate
{
public:
	LoadingLayer();

	CREATE_FUNC(LoadingLayer);

	bool init();

	static CCScene* scene();

protected:

	//�ڿ�ʼ��������ʾ�Ľ�����
	ProgressBar* _progressBar;

	//�ڽ���������ʾ������
	CCLabelTTF* _progressFg;

	//��Ҫ���ص�ͼƬ������
	int _numSp;

	//�Ѿ����ص�ͼƬ����
	int _loadedSp;

	//��ʼ��������
	void initProgressBar();

	//ProgressBar�н�������
	void loadingFinished();

	//ProgressBar�н�������
	void progressPercentageSetter(float percentage);

	//Ԥ������Դ
	void cacheInit(float delta);
};
