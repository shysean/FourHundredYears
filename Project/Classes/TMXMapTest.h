//
//  TMXMapTest.h
//  Project
//
//  Created by 史宏阳 on 1/8/15.
//
//

#ifndef __Project__TMXMapTest__
#define __Project__TMXMapTest__

#include "TestBaseScene.h"

class TMXMapTest : public TestBaseScene
{
public:
    TMXMapTest();
    virtual ~TMXMapTest();
    
    CREATE_FUNC(TMXMapTest);
    virtual bool init();
    virtual void initTestMethod();
    
    void testFunction();

};

#endif /* defined(__Project__TMXMapTest__) */
