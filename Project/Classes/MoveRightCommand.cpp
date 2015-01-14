//
//  MoveRightCommand.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "MoveRightCommand.h"
#include "Hero.h"

MoveRightCommand::MoveRightCommand()
{
    this->m_type = CommandType::MOVE_RIGHT;
}

MoveRightCommand::~MoveRightCommand()
{
    
}

void MoveRightCommand::execute(GameObject* obj, ...)
{
    Hero* hero = dynamic_cast<Hero*>(obj);
    CCLOG("MoveRightCommand execute %s", hero->getName().c_str());
    
    hero->move(0);
}