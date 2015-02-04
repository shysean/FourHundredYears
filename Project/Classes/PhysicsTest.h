//
//  PhysicsTest.h
//  Project
//
//  Created by shihongyang on 15/1/16.
//
//

#ifndef __Project__PhysicsTest__
#define __Project__PhysicsTest__

#include "TestBaseScene.h"

class Hero;

class PhysicsTest : public TestBaseScene
{
public:
    PhysicsTest();
    virtual ~PhysicsTest();
    
    virtual void initTestMethod();
    
    void update(float dt);
    
    void testHeroBody();
    void testHeroMoveLeft();
    void testHeroMoveRight();
    void testHeroMoveStop();
    void testContact();
    
    bool onContactBegin(PhysicsContact& contact);

    
protected:
    Hero* m_hero;
    int m_flag;
};

#endif /* defined(__Project__PhysicsTest__) */
