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
    
    int getType(){ return m_type; };
protected:
    int m_type;
};

#endif /* defined(__Project__Command__) */
