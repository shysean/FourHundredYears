//
//  TouchLayerTest.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__TouchLayerTest__
#define __Project__TouchLayerTest__

#include "TestBaseScene.h"

class Hero;

class TouchLayerTest : public TestBaseScene
{
public:
    TouchLayerTest();
    virtual ~TouchLayerTest();
    
    virtual void initTestMethod();
    
    void update(float delay);

    void testTouchLayer();
    
protected:
    Hero* m_hero;
};

#endif /* defined(__Project__TouchLayerTest__) */
