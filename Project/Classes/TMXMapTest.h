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
    
    virtual void initTestMethod();
    
    void update(float dt);
    
    void testFunction();
    void testPhys();
    
    void updatePosition();
//    void onEnter() override;

protected:
    TMXTiledMap* m_map;
    Sprite* m_flag;
    std::vector<Vec2> m_path;
};

#endif /* defined(__Project__TMXMapTest__) */
