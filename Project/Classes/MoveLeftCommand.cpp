//
//  MoveLeftCommand.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(int type)
{
    this->m_type = type;
}

MoveLeftCommand::~MoveLeftCommand()
{
    
}

void MoveLeftCommand::execute(GameObject* obj, ...)
{
    CCLOG("MoveLeftCommand execute");
}