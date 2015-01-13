//
//  TouchLayer.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__TouchLayer__
#define __Project__TouchLayer__

#include "cocos2d.h"

class TouchLayer : public cocos2d::Layer
{
public:
    TouchLayer();
    virtual ~TouchLayer();
    
    bool init() override;
    CREATE_FUNC(TouchLayer);
    
};

#endif /* defined(__Project__TouchLayer__) */
