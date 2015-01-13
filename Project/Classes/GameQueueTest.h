//
//  GameQueueTest.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef __Project__GameQueueTest__
#define __Project__GameQueueTest__

#include "TestBaseScene.h"
#include "GameQueue.h"

class GameQueueTest : public TestBaseScene
{
public:
    GameQueueTest();
    virtual ~GameQueueTest();
    virtual void initTestMethod();
    
    void testGameQueue();
    
    void enqueue(int num);
    void dequeue(int num);
    
protected:
    GameQueue<std::string> m_queue;
};

#endif /* defined(__Project__GameQueueTest__) */
