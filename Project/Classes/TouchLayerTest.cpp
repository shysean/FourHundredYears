//
//  TouchLayerTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#include "TouchLayerTest.h"
#include "TouchLayer.h"
#include "CommandManager.h"
#include "Hero.h"

TouchLayerTest::TouchLayerTest()
: m_hero(nullptr)
, m_ground(nullptr)
{
    initMenu();
    
    m_hero = Hero::create();
    m_hero->playAniByName("walk");
    m_hero->setPosition(Vec2(0,200));

    Size size = Director::getInstance()->getWinSize();
    m_ground = DrawNode::create();
    m_ground->setContentSize(Size(size.width*1.2, size.height));
    float x = size.width*1.2;
    float y = size.height;
    Vec2 vertices[] = { Vec2(50,50), Vec2(x-50,50), Vec2(x-50,y-50), Vec2(50,y-50) };
    m_ground->drawPoly(vertices, 4, true,  Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 1));
    
    this->addChild(m_ground);
    m_ground->addChild(m_hero);


    this->scheduleUpdate();
}

TouchLayerTest::~TouchLayerTest()
{
    
}

void TouchLayerTest::initTestMethod()
{
    ADD_TEST_METHOD(testTouchLayer);
    ADD_TEST_METHOD(testCameraFollow);
}

void TouchLayerTest::testTouchLayer()
{
    
    Size size = Director::getInstance()->getWinSize();

    auto touchLayer = TouchLayer::create();
    this->addChild(touchLayer);
    
}

void TouchLayerTest::testCameraFollow()
{

}

void TouchLayerTest::cameraFollow(GameObject* target, Node* container, Rect& innerBoundary, int dir)
{
    if (!target || !container) {
        return;
    }
    
    
    Size winSize = Director::getInstance()->getWinSize();
    Size containerSize = container->getContentSize();

    Vec2 containerPos = container->getPosition();

    Vec2 startPos(100,100);
    Vec2 targetPos = target->getPosition();
    
    if (targetPos.x <= 0) target->setPosition(Vec2(0,targetPos.y));
    if (targetPos.x >= containerSize.width) target->setPosition(Vec2(containerSize.width,targetPos.y));
    
    int paddingLeft = 0;
    int paddingRight = 500;
    
    Hero* h = dynamic_cast<Hero*>(target);
    int hdir = h->getDir();
    if (hdir==0 && targetPos.x >= paddingLeft /*innerBoundary.getMinX()*/ && (containerPos.x + containerSize.width) >= winSize.width )
    {
        

        int offsetX = targetPos.x - paddingLeft;// - innerBoundary.getMinX();
        container->setPosition(Vec2(-offsetX, containerPos.y));
//        CCLOG("%d %f", offsetX, targetPos.x);

    }
    
    if (hdir==1 && targetPos.x >= winSize.width /*innerBoundary.getMaxX()*/ && containerPos.x  <= 0 )
    {
        if (containerPos.x < (targetPos.x - winSize.width) - paddingRight) {
            CCLOG("bbb");
//            h->stand();
//            int offsetX = winSize.width-targetPos.x;
            container->setPosition(Vec2(containerPos.x + 2, containerPos.y));
        }
        else
        {
//            h->move(hdir);
            int offsetX = winSize.width-targetPos.x;// + (winSize.width - containerSize.width);// - containerSize.width;// - innerBoundary.getMaxX() + (containerSize.width - winSize.width);
            container->setPosition(Vec2(offsetX, containerPos.y));
            //        CCLOG("%d %f", offsetX, targetPos.x);
        }


    }
//    CCLOG("%f, %f", targetPos.x, containerPos.x);
}



void TouchLayerTest::update(float delay)
{
//    TestBaseScene::update(delay);
    
    if (m_hero) {
        m_hero->update(delay);
    }

    
    Rect rect = Rect(200, 0, m_ground->getContentSize().width-400, 10);
    Command* command = CommandManager::getInstance()->popCommand();
    while (command) {        
        command->execute(m_hero);
        CC_SAFE_DELETE(command);
        
        command = CommandManager::getInstance()->popCommand();
    }
    
    this->cameraFollow(m_hero, m_ground, rect, 2);

}