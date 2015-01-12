//
//  HeroTest.h
//  Project
//
//  Created by 史宏阳 on 1/12/15.
//
//

#ifndef __Project__HeroTest__
#define __Project__HeroTest__

#include "TestBaseScene.h"

class HeroTest : public TestBaseScene
{
public:
    HeroTest();
    virtual ~HeroTest();    
    virtual void initTestMethod();
    
    void testHeroName();
    void testHeroDisplay();

};

#endif /* defined(__Project__HeroTest__) */
