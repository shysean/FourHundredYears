//
//  GameQueueTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "GameQueueTest.h"
#include <thread>

GameQueueTest::GameQueueTest()
{
    initMenu();
}

GameQueueTest::~GameQueueTest()
{
    
}

void GameQueueTest::initTestMethod()
{
    ADD_TEST_METHOD(testGameQueue);
}

void GameQueueTest::enqueue(int num)
{
    for (int i = 0; i < num; i++) {
        char info[100];
        sprintf(info, "%d", i);
        CCLOG("Enqueue:%s",info);
        m_queue.push(info);
        
        std::chrono::milliseconds dura( 10 );
        std::this_thread::sleep_for( dura );
    }
}

void GameQueueTest::dequeue(int num)
{
    while (true) {
    
        if (!m_queue.empty()) {
            
            std::string value = m_queue.readAndPop();
            CCLOG("Dequeue:%s",value.c_str());
            
            num--;
            if (num <= 0) {
                CCLOG("break");
                break;
            }

            std::chrono::milliseconds dura( 20 );
            std::this_thread::sleep_for( dura );
        }
    }
}

void GameQueueTest::testGameQueue()
{
    std::thread enthread(&GameQueueTest::enqueue, this, 20);
    std::thread dethread(&GameQueueTest::dequeue, this, 20);

    enthread.join();
    dethread.join();
}

