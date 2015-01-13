//
//  WorldScene.cpp
//  Project
//
//  Created by 史宏阳 on 1/10/15.
//
//

#include "WorldScene.h"
#include "WorldMap.h"

USING_NS_CC;


WorldScene::WorldScene()
: m_map(nullptr)
{
    WorldScene::initWithPhysics();
}

WorldScene::~WorldScene()
{

}

void WorldScene::onEnter()
{
    Scene::onEnter();

    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    Size size = Director::getInstance()->getWinSize();
    
    auto ground = Node::create();
    ground->setPhysicsBody(PhysicsBody::createEdgeSegment(Vec2(0, 50), Vec2(size.width, 50)));
    this->addChild(ground);
}
