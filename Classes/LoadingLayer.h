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

	//在开始场景中显示的进度条
	ProgressBar* _progressBar;

	//在进度条上显示的文字
	CCLabelTTF* _progressFg;

	//需要加载的图片总数量
	int _numSp;

	//已经加载的图片数量
	int _loadedSp;

	//初始化进度条
	void initProgressBar();

	//ProgressBar中将调用它
	void loadingFinished();

	//ProgressBar中将调用它
	void progressPercentageSetter(float percentage);

	//预加载资源
	void cacheInit(float delta);
};
