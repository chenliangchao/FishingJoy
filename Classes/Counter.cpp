#include "Counter.h"
enum{
    k_Counter_Action = 0
};
Counter* Counter::create(CCArray* presenters, int digit/* = 0 */)
{
	//中文不支持 需要为偶数个中文或者在中文后加 . 
	CCAssert(digit>=0 && digit<=10, "金币为0-9之间的数字.");
    Counter *counter = new Counter;
	if (counter && counter->init(presenters,digit) )
	{   
		counter->autorelease();
		return counter;
	}
	else
	{
		CC_SAFE_DELETE(counter);
		return NULL;
	}

}
bool Counter::init(CCArray* presenters, int digit/* = 0 */)
{
	if (!CCNode::init())
	{
		return false;
	}
    _presenters = CCNode::create();

	CCObject *obj = NULL;
	int i = 0;
	CCARRAY_FOREACH(presenters, obj)
	{
		CCNode *node = (CCNode *)obj;
		_presenters->addChild(node,0,i);
		node->setPosition(ccp(0, node->getContentSize().height * i));
		i++;
	}
    this->addChild(_presenters);
    setDigit(digit);
    return true;
}
void Counter::setDigit(int digit)
{
    if(_digit != digit)
	{
        _digit = digit;
        animation();
    }
}
int Counter::getDigit()
{
    return _digit;
}
void Counter::animation()
{
	CCNode *node = (CCNode *)_presenters->getChildByTag(_digit);
    CCPoint position = node->getPosition();
    _presenters->stopActionByTag(k_Counter_Action);
    CCMoveTo* moveTo = CCMoveTo::create(0.3f, ccp(0, -position.y));
	moveTo->setTag(k_Counter_Action);
    _presenters->runAction(moveTo);
}
void Counter::visit()
{

    glEnable(GL_SCISSOR_TEST);
    CCSize size = ((CCNode *)_presenters->getChildByTag(_digit))->getContentSize();
    CCPoint position = getParent()->convertToWorldSpace(getPosition());
    glScissor((position.x - size.width / 2) * 0.4, (position.y - size.height / 2) * 0.4, size.width* 0.4, size.height* 0.4);

    CCNode::visit();
    glDisable(GL_SCISSOR_TEST);
}