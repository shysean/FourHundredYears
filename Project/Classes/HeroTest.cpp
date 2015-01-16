//
//  HeroTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/12/15.
//
//

#include "HeroTest.h"
#include "Hero.h"

HeroTest::HeroTest()
{
    initMenu();
}

HeroTest::~HeroTest()
{
    
}

void HeroTest::initTestMethod()
{
    ADD_TEST_METHOD(testHeroName);
    ADD_TEST_METHOD(testHeroDisplay);
    ADD_TEST_METHOD(testHeroMove);
}

void HeroTest::testHeroName()
{
    auto hero = Hero::create();
    CCLOG("Hero name: %s", hero->getName().c_str());
    hero->setName("Hero");
    CCLOG("Hero name:%s", hero->getName().c_str());
}

void HeroTest::testHeroDisplay()
{
    const char* names[11] = {"all","walk","tunnleft", "climb", "turnright", "fall", "getup", "freeze", "wake", "pick", "sleep"};
    
    for (int i = 0; i < 11; i ++) {
        auto hero = Hero::create();
        hero->setPosition(Vec2(50 * i,100));
        hero->playAniByName(names[i]);
        addChild(hero);
    }

}

void HeroTest::testHeroMove()
{
    Size s = Director::getInstance()->getWinSize();

    auto hero = Hero::create();
    hero->playAniByName("walk");
    hero->setPosition(Vec2(s.width / 3, s.height / 5));
    this->addChild(hero);
    
    auto array = PointArray::create(20);
    
    array->addControlPoint(Vec2(0, 0));
    array->addControlPoint(Vec2(100, 0));
    array->addControlPoint(Vec2(150, 50));
    array->addControlPoint(Vec2(200, 100));
    array->addControlPoint(Vec2(300, 100));
    array->addControlPoint(Vec2(300, 0));
    array->addControlPoint(Vec2(200, 0));
    array->addControlPoint(Vec2(100, 0));
    array->addControlPoint(Vec2(0, 0));
    
    auto action = CardinalSplineBy::create(6, array, 1);
    hero->runAction(action);
}