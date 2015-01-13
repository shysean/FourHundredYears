//
//  MoveLeftCommand.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__MoveLeftCommand__
#define __Project__MoveLeftCommand__

#include "Command.h"

class MoveLeftCommand : public Command
{
public:
    MoveLeftCommand(int type);
    virtual ~MoveLeftCommand();
    
    virtual void execute(GameObject* obj, ...) override;
};

#endif /* defined(__Project__MoveLeftCommand__) */
