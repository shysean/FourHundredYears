//
//  TMXMapTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/8/15.
//
//

#include "TMXMapTest.h"

TMXMapTest::TMXMapTest()
: m_map(nullptr)
, m_flag(nullptr)
{
    TMXMapTest::initWithPhysics();
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    initMenu();
}

TMXMapTest::~TMXMapTest()
{
    m_map = nullptr;
    m_flag = nullptr;
}

//void TMXMapTest::onEnter()
//{
//    CCLOG("TMXMapTest onEnter");
//
//    Scene::onEnter();
//}



void TMXMapTest::initTestMethod()
{
    ADD_TEST_METHOD(testFunction);
    ADD_TEST_METHOD(testPhys);
    
}

void TMXMapTest::update(float dt)
{
    Scene::update(dt);
//    if (m_map) {
//        m_map->setPosition(m_map->getPosition()+Vec2(5, 0));
//    }
    
    if (m_flag) {
//        CCLOG("(%f,%f)", m_flag->getPosition().x, m_flag->getPosition().y);
        CCLOG("%f", m_flag->getPhysicsBody()->getVelocity().x);
//        m_flag->getPhysicsBody()->setVelocity(Vect(10.f,0.0f));
        if (m_flag->getPosition().x >= 80)
        {
//            m_flag->getPhysicsBody()->setVelocity(Vec2(0,0));
        }
        if (m_flag->getPhysicsBody()->getVelocity().x < 40.0f) {
            m_flag->getPhysicsBody()->applyImpulse(Vec2(200.0f, 0.0f));
        }else
        {
            m_flag->getPhysicsBody()->setVelocity(Vect(40.f,0.0f));
        }
    }
}

void TMXMapTest::updatePosition()
{
    auto point = m_flag->getPosition();
    CCLOG("%f,%f", point.x, point.y);
    for (int i = 0; i < m_path.size(); i++) {
        Vec2 lastPoint = m_path.at(i);
        Vec2 nextPoint = m_path.at(i);
        if (i < m_path.size() - 1)
        {
            nextPoint = m_path.at(i + 1);
        }
        
        if (point.x >= lastPoint.x && point.x <= nextPoint.x)
        {
            int y = lastPoint.y + (nextPoint.y - lastPoint.y) * ((point.x - lastPoint.x) / (nextPoint.x - lastPoint.x));
            m_flag->setPosition(Vec2(point.x + 1, y));
            return;
        }
    }
}



void TMXMapTest::testFunction()
{
    CCLOG("testFunction");
    
    m_map = TMXTiledMap::create("map/test_map.tmx");
    
    auto path = m_map->getObjectGroup("path");
    for (auto v : path->getObjects()) {
        auto object = v.asValueMap();
        float x = object["x"].asFloat();
        float y = object["y"].asFloat();
        m_path.push_back(Vec2(x,y));
    }
    addChild(m_map);
    
    m_flag = Sprite::create("test.png");
    m_flag->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    addChild(m_flag);
}

void TMXMapTest::testPhys()
{
    Size size = Director::getInstance()->getWinSize();
    
    m_map = TMXTiledMap::create("map/test_map2.tmx");
    auto layer = m_map->getLayer("mapLayer");
    Size layerSize = layer->getLayerSize();
    
    
    for (auto g: m_map->getObjectGroups())
    {
        CCLOG("%s", g->getGroupName().c_str());
    }
    
    addChild(m_map);
    
    for(int row = 0; row < layerSize.height; row++) {
        for (int col = 0; col < layerSize.width; col++) {
            auto sprite = layer->getTileAt(Vec2(col, row));
            int gid = layer->getTileGIDAt(Vec2(col,row));
            
            if (sprite) {
                auto p = layer->getPositionAt(Vec2(col,row));
                sprite->setPosition(p + Vec2(m_map->getTileSize() / 2));
                
                if (gid == 9) {
                    Vec2 poins[4];
                    poins[1] = Vec2(-8,-8);
                    poins[2] = Vec2(8,8);
                    poins[3] = Vec2(8,-8);
                    poins[4] = Vec2(-8,-8);
                    auto body = PhysicsBody::createEdgePolygon(poins, 4);
                    
                    body->setGravityEnable(false);
                    body->setDynamic(false);
                    sprite->setPhysicsBody(body);                }
                else
                {
                    auto body = PhysicsBody::createBox(sprite->getContentSize());
                    body->setGravityEnable(false);
                    body->setDynamic(false);
                    sprite->setPhysicsBody(body);
                }
                
            }
        }
    }
    

    
    ValueMap playerSpawnPoint = m_map->getObjectGroup("spawn")->getObject("player");
    float x = playerSpawnPoint["x"].asFloat();
    float y = playerSpawnPoint["y"].asFloat();
    
    
    m_flag = Sprite::create("test.png");
    m_flag->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    m_flag->setPosition(Vec2(x, y - 16));
//    auto flagBody = PhysicsBody::createBox(m_flag->getContentSize());
    auto flagBody = PhysicsBody::createCircle(m_flag->getContentSize().width / 2);
    m_flag->setPhysicsBody(flagBody);
    this->addChild(m_flag);
    
//    flagBody->applyImpulse(Vect(1400.0f,0.0f));
    flagBody->setAngularDamping(100000);
//    flagBody->setAngularVelocity(60);
    flagBody->setAngularVelocityLimit(0);
    flagBody->setGravityEnable(true);
    flagBody->setVelocityLimit(50);
    flagBody->setVelocity(Vec2(40.0f, 0.0f));
    flagBody->setLinearDamping(0);
    
//    auto winSize = Director::getInstance()->getWinSize();
//    auto currentVelocity = flagBody->getLinearDamping() GetLinearVelocity();
//    auto impulse(0.0f,0.0f);
//    fabsf(<#float#>)
//    // walk
//    if (location.y < (winSize.height * 0.5f))
//    {
//        // apply impulse if x velocity is getting low
//        if (fabsf(currentVelocity.x) < 5.0f)
//        {
//            impulse.y = 0.0f;
//            impulse.x = 200.0f * delta;
//            if (location.x < (winSize.width * 0.5f))
//                impulse.x = -impulse.x;
//            this->body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
//        }
//    }


}

