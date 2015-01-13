//
//  MoveRightCommand.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__MoveRightCommand__
#define __Project__MoveRightCommand__

#include "Command.h"

class MoveRightCommand : public Command
{
public:
    MoveRightCommand(int type);
    virtual ~MoveRightCommand();
    
    virtual void execute(GameObject* obj, ...) override;
};

#endif /* defined(__Project__MoveRightCommand__) */
