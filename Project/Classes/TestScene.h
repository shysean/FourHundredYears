//
//  TestScene.h
//  Project
//
//  Created by shihongyang on 15/1/8.
//
//

#ifndef __Project__TestScene__
#define __Project__TestScene__

#include "cocos2d.h"
#include "CocosGUI.h"

class TestScene : public cocos2d::Scene
{
public:
    TestScene();
    virtual ~TestScene();
    
    CREATE_FUNC(TestScene)
    
    virtual bool init() override;
    
};

#endif /* defined(__Project__TestScene__) */
