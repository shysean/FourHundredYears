//
//  TouchLayerTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "TouchLayerTest.h"
#include "TouchLayer.h"
#include "CommandManager.h"
#include "Hero.h"

TouchLayerTest::TouchLayerTest()
: m_hero(nullptr)
{
    initMenu();
    
    this->scheduleUpdate();
}

TouchLayerTest::~TouchLayerTest()
{
    
}

void TouchLayerTest::initTestMethod()
{
    ADD_TEST_METHOD(testTouchLayer);
}

void TouchLayerTest::testTouchLayer()
{
    m_hero = Hero::create();
    m_hero->playAniByName("walk");
    Size size = Director::getInstance()->getWinSize();
    m_hero->setPosition(Vec2(size.width / 2, size.height / 3));
    this->addChild(m_hero);
    
    auto touchLayer = TouchLayer::create();
    this->addChild(touchLayer);
}

void TouchLayerTest::update(float delay)
{
    TestBaseScene::update(delay);
    
    if (m_hero) {
        m_hero->update(delay);
    }
    
    Command* command = CommandManager::getInstance()->popCommand();
    while (command) {
        int type = command->getType();
        CCLOG("Type=%d", type);
        
        command->execute(m_hero);
        CC_SAFE_DELETE(command);
        
        command = CommandManager::getInstance()->popCommand();
    }
}