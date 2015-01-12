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