//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : FishingJoy
//  @ File Name : StaticData.cpp
//  @ Date : 2017/9/29
//  @ Author : chenliangchao
//
//


#include "StaticData.h"

static StaticData* g_sharedStaticData = NULL;

StaticData* StaticData::sharedStaticData() 
{
	if (g_sharedStaticData == NULL) {
		g_sharedStaticData = new StaticData();
		g_sharedStaticData->init();
	}
	return g_sharedStaticData;
}

void StaticData::purge() 
{
	CC_SAFE_RELEASE_NULL(g_sharedStaticData);
}

int StaticData::intValueFromKey(const std::string &key) 
{
	return _dictionary->valueForKey(key)->intValue();
}

const char* StaticData::stringValueFromKey(const std::string &key) 
{
	return _dictionary->valueForKey(key)->getCString();
}

float StaticData::floatValueFromKey(const std::string &key) 
{
	return _dictionary->valueForKey(key)->floatValue();
}

//根据键值得到bool类型数据
bool StaticData::booleanFromKey(const std::string &key)
{
	return _dictionary->valueForKey(key)->boolValue();
}

//根据键值得到point类型数据
cocos2d::CCPoint StaticData::pointFromKey(const std::string &key) 
{
	return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}

//根据键值得到rect类型数据
cocos2d::CCRect StaticData::rectFromKey(const std::string &key) 
{
	return CCRectFromString(_dictionary->valueForKey(key)->getCString());
}

cocos2d::CCSize StaticData::sizeFromKey(const std::string &key) 
{
	return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}

bool StaticData::init() 
{
  //创建出词典对象
	_dictionary = CCDictionary::createWithContentsOfFile(_staticFileName.c_str());
	_dictionary->retain();

	return true;
}

StaticData::~StaticData() 
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}

StaticData::StaticData() 
{

}

