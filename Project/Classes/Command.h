//
//  Command.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__Command__
#define __Project__Command__

#include "cocos2d.h"
#include "CommandType.h"
#include "GameObject.h"

class Command : public cocos2d::Ref
{
public:
    Command() {};
    virtual ~Command() {};
    
    virtual void execute(GameObject* obj, ...) = 0;
    
    CC_SYNTHESIZE(int, m_type, Type);

};

#endif /* defined(__Project__Command__) */
