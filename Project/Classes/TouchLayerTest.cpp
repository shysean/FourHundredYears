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

TouchLayerTest::TouchLayerTest()
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
    auto touchLayer = TouchLayer::create();
    this->addChild(touchLayer);
}

void TouchLayerTest::update(float delay)
{
    Command* command = CommandManager::getInstance()->popCommand();
    while (command) {
        int type = command->getType();
        CCLOG("Type=%d", type);
        
        command->execute(nullptr);
        CC_SAFE_DELETE(command);
        
        command = CommandManager::getInstance()->popCommand();
    }
}