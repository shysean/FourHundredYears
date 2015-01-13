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

class TouchLayerTest : public TestBaseScene
{
public:
    TouchLayerTest();
    virtual ~TouchLayerTest();
    
    virtual void initTestMethod();
    
    void update(float delay);

    void testTouchLayer();
};

#endif /* defined(__Project__TouchLayerTest__) */
