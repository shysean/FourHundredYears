//
//  GameObject.h
//  Project
//
//  Created by 史宏阳 on 1/12/15.
//
//

#ifndef __Project__GameObject__
#define __Project__GameObject__

#include "cocos2d.h"

class GameObject : public cocos2d::Node
{
public:
    GameObject();
    virtual ~GameObject();
    
    CC_SYNTHESIZE(std::string, m_name, Name);
    CC_SYNTHESIZE(cocos2d::Sprite*, m_sprite, Sprite);
    
};

#endif /* defined(__Project__GameObject__) */
