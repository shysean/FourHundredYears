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
class GameObject;

class TouchLayerTest : public TestBaseScene
{
public:
    TouchLayerTest();
    virtual ~TouchLayerTest();
    
    virtual void initTestMethod();
    
    void update(float delay);

    void testTouchLayer();
    void testCameraFollow();
    
protected:
    void cameraFollow(GameObject* targe, Node* container, Rect& innerBoundary, int dir);
    
    
protected:
    Hero* m_hero;
    DrawNode* m_ground;
    
};

#endif /* defined(__Project__TouchLayerTest__) */
