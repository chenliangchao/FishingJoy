#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "MenuLayer.h"
#include "CannonLayer.h"
#include "TouchLayer.h"
#include "Fish.h"
#include "PanelLayer.h"
#include "FishingJoyData.h"

USING_NS_CC;

typedef enum{
	k_Operate_Pause = 0,
	k_Operate_Resume
}OperateFlag;

class GameScene :
	public CCScene
{
public:
	GameScene(void);
	CREATE_FUNC(GameScene)
	virtual bool init();
	virtual ~GameScene();
	void cannonAimAt(CCPoint target);
	void cannonShootTo(CCPoint target);

	void pause();
	void resume();
	void sound();
	void music();
	void reset();
	void transToMainMenu();

	//增加金币的数值
	void scheduleTimeUp();

protected:
	BackgroundLayer* _backgroundLayer;
	FishLayer* _fishLayer;
	MenuLayer* _menuLayer;
	CannonLayer* _cannonLayer;
	TouchLayer* _touchLayer;
	PanelLayer* _panelLayer;
	bool checkOutCollisionBetweenFishesAndBullet(Bullet* bullet);
	void checkOutCollision();
	virtual void update(float delta);
	void fishWillBeCaught(Fish* fish);
	void alterGold(int delta);
	void checkOutCollisionBetweenFishesAndFishingNet(Bullet* bulet);
	void operateAllSchedulerAndActions(CCNode* node, OperateFlag flag);
};

