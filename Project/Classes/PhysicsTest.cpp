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
//    body->setCategoryBitmask(0x00);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(winSize.width/2,winSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
    
    
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [](PhysicsContact& contact)
    {
//        auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
//        auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
//        
//        if (spriteA && spriteA->getTag() == 1 && spriteB && spriteB->getTag() == 1)
//        {
//            spriteA->setColor(Color3B::YELLOW);
//            spriteB->setColor(Color3B::YELLOW);
//        }
        
        log("onContactBegin");
        return true;
    };
    
    
    listener->onContactPreSolve = [] (PhysicsContact& contact, PhysicsContactPreSolve& solve)
    {
        log("onContactPreSolve");
        return true;
    };
    
    
    listener->onContactPostSolve = [] (PhysicsContact& contact,const PhysicsContactPostSolve& solve)
    {
        log("onContactPostSolve");
    };
    
    
    listener->onContactSeperate = [](PhysicsContact& contact) {
        auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
        auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();
        
        if (spriteA && spriteA->getTag() == 1 && spriteB && spriteB->getTag() == 1)
        {
            spriteA->setColor(Color3B::WHITE);
            spriteB->setColor(Color3B::WHITE);
        }
        log("onContactSeperate");
    };
    
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener,1);
    

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
    ADD_TEST_METHOD(testContact);

}

void PhysicsTest::update(float dt)
{
    Scene::update(dt);

    
    if (m_hero) {
        auto body = m_hero->getPhysicsBody();

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
/*  
 * 两个body的CategoryBitmask与对方的CollisionBitmask 有任意一组与运算 = 0 不碰撞
 * 两个body的CategoryBitmask与对方的ContactTestBitmask 有任意一组与运算 = 0 不通知
 *
 */
void PhysicsTest::testContact()
{
    auto node = Node::create();
    node->setPosition(100, 100);
    node->setContentSize(Size(50, 50));
    
    auto body = PhysicsBody::createBox(Size(50,50));
    body->setGravityEnable(false);
    
    body->setCategoryBitmask(0x0111);
    body->setContactTestBitmask(0x0100);
    body->setCollisionBitmask(0x0001);
    
    node->setPhysicsBody(body);

    this->addChild(node);
    body->applyImpulse(Vect(30000,0));
    
    
    auto staticNode = Node::create();
    staticNode->setPosition(200, 100);
    
    auto staticBody = PhysicsBody::createBox(Size(50,50));
    staticBody->setGravityEnable(false);
    staticBody->setCategoryBitmask(0x0101);
    staticBody->setContactTestBitmask(0x0010);
    staticBody->setCollisionBitmask(0x0100);

    staticNode->setPhysicsBody(staticBody);
    this->addChild(staticNode);
}

bool PhysicsTest::onContactBegin(PhysicsContact& contact)
{
    CCLOG("onContactBegin");
    return true;
}

void PhysicsTest::testHeroBody()
{
    Size winSize = Director::getInstance()->getWinSize();

    m_hero = Hero::create();
    m_hero->playAniByName("walk");
    m_hero->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.5));
    
    auto material = PhysicsMaterial(1.0f, 0.0f, 0.1f);
    auto body = PhysicsBody::createBox(m_hero->getContentSize(), material);
//    body->setContactTestBitmask(0x00);
//    body->setCategoryBitmask(0x01);
    m_hero->setPhysicsBody(body);
    this->addChild(m_hero);


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

}