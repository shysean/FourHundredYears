//
//  MoveLeftCommand.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "MoveLeftCommand.h"
#include "Hero.h"

MoveLeftCommand::MoveLeftCommand()
{
    this->m_type = CommandType::MOVE_LEFT;
}

MoveLeftCommand::~MoveLeftCommand()
{
    
}

void MoveLeftCommand::execute(GameObject* obj, ...)
{
    Hero* hero = dynamic_cast<Hero*>(obj);

    CCLOG("MoveLeftCommand execute %s", hero->getName().c_str());
    
    hero->move(1);

}