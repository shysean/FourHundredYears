//
//  Hero.cpp
//  Project
//
//  Created by 史宏阳 on 1/12/15.
//
//

#include "Hero.h"

USING_NS_CC;

Hero::Hero()
: RES_HERO("hero.png")
, dir(0)
, state(0)
{
    this->setName("Hero");
}

Hero::~Hero()
{
    
}

bool Hero::init()
{
    int size = 32;
    this->setContentSize(Size(size,size));
    this->setAnchorPoint(Vec2(0.5,0));
    
    initAnimation();
    
    m_sprite = Sprite::create();
    m_sprite->setAnchorPoint(Vec2(0.5,0));
    m_sprite->setPosition(Vec2(size * 0.5, 0));
    this->addChild(m_sprite);
    
    return true;
}

void Hero::playAniByName(std::string name)
{
    auto animation = AnimationCache::getInstance()->getAnimation(name);
    if (!animation)
    {
        CCLOGWARN("Can't find animation : %s", name.c_str());
        return;
    }
    auto action = RepeatForever::create(Animate::create(animation));
    m_sprite->stopAllActions();
    m_sprite->runAction(action);
}

void Hero::initAnimation()
{
//    initAnimation("all", 0, 48);
    initAnimation("walk",       0, 4);
    initAnimation("tunnleft",   5, 8);
    initAnimation("climb",      9, 10);
    initAnimation("turnright",  11, 14);
    initAnimation("fall",       15, 18);
    initAnimation("getup",      19, 23);
    initAnimation("freeze",     24, 27);
    initAnimation("wake",       28, 36);
    initAnimation("pick",       37, 43);
    initAnimation("sleep",      44, 47);
}

void Hero::initAnimation(std::string name, int startPos, int endPos, bool isRestore/* = true*/)
{
    int size = 32;
    
    auto animation = Animation::create();
    
    for( int i = startPos; i <= endPos; i++)
    {
        int x = (int)i % 8;
        int y = (int)i / 8;
//        CCLOG("%i(%d,%d)",i, x, y);
        
        Rect rect(x * size, y * size + 1, size, size);
        auto frame = SpriteFrame::create(RES_HERO, rect);
        animation->addSpriteFrame(frame);
    }
    // should last 2.8 seconds. And there are 14 frames.
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(isRestore);
    
    AnimationCache::getInstance()->addAnimation(animation, name);
}

void Hero::move(int dir)
{
    this->dir = dir;
    this->state = 1;
}

void Hero::stand()
{
    this->state = 0;
}

void Hero::update(float delay)
{
    if (this->state == 1) {
    
        auto pos = this->getPosition();
        if (this->dir == 0)
        {
            this->setPosition(Vec2(pos.x + 0.3, pos.y));
            m_sprite->setFlippedX(false);
        }
        else
        {
            this->setPosition(Vec2(pos.x - 0.3, pos.y));
            m_sprite->setFlippedX(true);
        }
    }
}