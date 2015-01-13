//
//  CommandManager.h
//  Project
//
//  Created by 史宏阳 on 1/14/15.
//
//

#ifndef __Project__CommandManager__
#define __Project__CommandManager__

#include "GameQueue.h"
#include "Command.h"

class CommandManager
{
public:
    static CommandManager* getInstance();
    
    void addCommand(Command* command);
    Command* popCommand();
    
    bool hasCommand();

private:
    CommandManager(){};
    
protected:
    GameQueue<Command*> m_commandQueue;
};

#endif /* defined(__Project__CommandManager__) */
