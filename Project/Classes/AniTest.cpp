//
//  AniTest.cpp
//  Project
//
//  Created by 史宏阳 on 2/4/15.
//
//

#include "AniTest.h"
#include "SeasonObject.h"

AniTest::AniTest()
: m_seasonObject(nullptr)
, m_season(GameConst::SEASON::SPRING)
{
    initMenu();
}

AniTest::~AniTest()
{
    
}

void AniTest::initTestMethod()
{
    ADD_TEST_METHOD(testChange);
    ADD_TEST_METHOD(testSeasonObject);
    ADD_TEST_METHOD(testChangeSeason);
    
}

void AniTest::testChange()
{
    CCLOG("Test change");
    

    for(int i = 0; i < 4; i++)
    {
        Rect rect(0, i*16, 64, 16);
        auto frame = SpriteFrame::create("testEarth.png", rect);
        char name[20];
        sprintf(name, "earth%d", i);
        SpriteFrameCache::getInstance()->addSpriteFrame(frame, name);
    }
    
    auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("earth0");
    auto sprite1 = Sprite::createWithSpriteFrame(frame);
    sprite1->setPosition(Vec2(100, 100));
    this->addChild(sprite1);
    
    

    frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("earth1");
    auto sprite2 = Sprite::createWithSpriteFrame(frame);
    sprite2->setPosition(Vec2(100, 100));
    this->addChild(sprite2);
    sprite2->setOpacity(0);
    
    auto fadeInAction = FadeIn::create(5);
    auto fadeOutAction = fadeInAction->reverse();
    
    sprite1->runAction(fadeOutAction);
    sprite2->runAction(fadeInAction);
    
    
}

void AniTest::testSeasonObject()
{
    m_seasonObject = new SeasonObject();
    m_seasonObject->setPosition(Vec2(150, 150));
    this->addChild(m_seasonObject);
}

void AniTest::testChangeSeason()
{
    if(m_seasonObject == nullptr)
    {
        return;
    }
    m_season = m_season + 1;
    if (m_season > GameConst::SEASON::WINTER) {
        m_season = GameConst::SEASON::SPRING;
    }
    m_seasonObject->changeSeason((GameConst::SEASON)m_season, 5);
}
