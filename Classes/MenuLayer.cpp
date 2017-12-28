#include "MenuLayer.h"
#include "GameScene.h"
USING_NS_CC;

bool MenuLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	this->createBackground();
	this->createMenu();
	return true;
}

void MenuLayer::createBackground()
{
	//RGBA 255为不透明， 范围0-255，越大颜色越深
	CCLayerColor* colorBackground = CCLayerColor::create(ccc4(0, 0, 0, 170));
	this->addChild(colorBackground);
}

void MenuLayer::createMenu()
{
	int fontSize = 60;
	CCString* fontName = CCString::create("Thonburi");

	CCMenuItemLabel* resume = CCMenuItemLabel::create(CCLabelTTF::create("继续游戏", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::resume));

	CCMenuItemLabel* mainMenu = CCMenuItemLabel::create(CCLabelTTF::create("回主菜单.", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::toMainMenu));

	//CCMenuItemLabel* soundOn = CCMenuItemLabel::create(CCLabelTTF::create("音效开.", fontName->getCString(), fontSize));
	//CCMenuItemLabel* soundOff = CCMenuItemLabel::create(CCLabelTTF::create("音效关.", fontName->getCString(), fontSize));
	//_sound = CCMenuItemToggle::createWithTarget(this, menu_selector(MenuLayer::sound),  soundOff, soundOn, NULL);

	CCMenuItemLabel* musicOn = CCMenuItemLabel::create(CCLabelTTF::create("音乐开", fontName->getCString(), fontSize));
	CCMenuItemLabel* musicOff = CCMenuItemLabel::create(CCLabelTTF::create("音乐关闭", fontName->getCString(), fontSize));
	_music = CCMenuItemToggle::createWithTarget(this, menu_selector(MenuLayer::music), musicOff, musicOn, NULL);

	CCMenuItemLabel* reset = CCMenuItemLabel::create(CCLabelTTF::create("重置游戏", fontName->getCString(), fontSize), this, menu_selector(MenuLayer::reset));

	CCMenu* menu = CCMenu::create(resume, mainMenu, /*_sound,*/ _music, reset, NULL);
	menu->alignItemsVerticallyWithPadding(20);
	this->addChild(menu);
}

void MenuLayer::resume(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->resume();
}

void MenuLayer::toMainMenu(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->toMainMenu();
}

/*void MenuLayer::sound(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->sound();
}*/

void MenuLayer::music(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->music();
}

void MenuLayer::reset(CCObject* pSender)
{
	GameScene* gameScene = (GameScene*)this->getParent();
	gameScene->reset();
}
