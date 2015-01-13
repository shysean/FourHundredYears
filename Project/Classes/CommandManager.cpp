//
//  CommandManager.cpp
//  Project
//
//  Created by 史宏阳 on 1/14/15.
//
//

#include "CommandManager.h"

static CommandManager *m_instance = nullptr;

CommandManager* CommandManager::getInstance()
{
    if (!m_instance)
    {
        m_instance = new (std::nothrow) CommandManager();
    }
    
    return m_instance;
}

void CommandManager::addCommand(Command *command)
{
    m_commandQueue.push(command);
}

Command* CommandManager::popCommand()
{
    if (hasCommand()) {
        return m_commandQueue.readAndPop();
    }
    
    return nullptr;
}

bool CommandManager::hasCommand()
{
    return !m_commandQueue.empty();
}