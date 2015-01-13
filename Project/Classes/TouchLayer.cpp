//
//  TouchLayer.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "TouchLayer.h"
#include "CommandManager.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

USING_NS_CC;

TouchLayer::TouchLayer()
{
    
}

TouchLayer::~TouchLayer()
{
    
}

bool TouchLayer::init()
{
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch, Event* event){
        auto winSize = Director::getInstance()->getWinSize();

        auto pos = touch->getLocation();
        if (pos.x < winSize.width * 0.5)
        {
            CCLOG("GO LEFT");
            auto command = new MoveLeftCommand(CommandType::MOVE_LEFT);
            CommandManager::getInstance()->addCommand(command);
        }else
        {
            CCLOG("GO RIGHT");
            auto command = new MoveRightCommand(CommandType::MOVE_LEFT);
            CommandManager::getInstance()->addCommand(command);
        }
        return true;
    };
    listener->onTouchEnded = [](Touch* touch, Event* event){
        CCLOG("STOP");
    };
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}


