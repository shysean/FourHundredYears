//
//  MoveRightCommand.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(int type)
{
    this->m_type = type;
}

MoveRightCommand::~MoveRightCommand()
{
    
}

void MoveRightCommand::execute(GameObject* obj, ...)
{
    CCLOG("MoveRightCommand execute");
}