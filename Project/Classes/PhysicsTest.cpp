//
//  PhysicsTest.cpp
//  Project
//
//  Created by shihongyang on 15/1/16.
//
//

#include "PhysicsTest.h"
#include "Hero.h"

PhysicsTest::PhysicsTest()
: m_hero(nullptr)
, m_flag(0)
{
    initMenu();

    
    PhysicsTest::initWithPhysics();
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    this->getPhysicsWorld()->setGravity(Vect(0,-200));
    
    Size winSize = Director::getInstance()->getWinSize();
    auto body = PhysicsBody::createEdgeBox(winSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(winSize.width/2,winSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
}

PhysicsTest::~PhysicsTest()
{
    
}

void PhysicsTest::initTestMethod()
{
    ADD_TEST_METHOD(testHeroBody);
    ADD_TEST_METHOD(testHeroMoveLeft);
    ADD_TEST_METHOD(testHeroMoveRight);
    ADD_TEST_METHOD(testHeroMoveStop);

}

void PhysicsTest::update(float dt)
{
    Scene::update(dt);

    
    if (m_hero) {
        auto body = m_hero->getPhysicsBody();

//        if (m_flag == 0)
//        {
//            body->get
//        }
//        else
        {
            if (abs(body->getVelocity().x) < 10.0f) {
                body->applyForce(Vect(30000.0f * m_flag ,0));
            }
            if (abs(body->getVelocity().x) > 10.0f) {
                body->setVelocity(Vect(m_flag * 10.0f, 0));
            }
        }
        
    }
}

void PhysicsTest::testHeroBody()
{
    Size winSize = Director::getInstance()->getWinSize();

    m_hero = Hero::create();
    m_hero->playAniByName("walk");
    m_hero->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(m_hero);
    
    auto material = PhysicsMaterial(1.0f, 0.0f, 0.1f);
    auto body = PhysicsBody::createBox(m_hero->getContentSize(), material);
//    body->setVelocityLimit(10.0f);
//    body->setDynamic(false);        // staic
//    body->setResting(false);
    m_hero->setPhysicsBody(body);
}

void PhysicsTest::testHeroMoveLeft()
{
    this->m_flag = -1;
}

void PhysicsTest::testHeroMoveRight()
{
    this->m_flag = 1;
}

void PhysicsTest::testHeroMoveStop()
{
    this->m_flag = 0;
}