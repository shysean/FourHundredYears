//
//  SeasonObject.cpp
//  Project
//
//  Created by 史宏阳 on 2/4/15.
//
//

#include "SeasonObject.h"

USING_NS_CC;

SeasonObject::SeasonObject()
: m_season(GameConst::SEASON::NONE)
, m_currSprite(nullptr)
, m_nextSprite(nullptr)
{
    initSeason();
}

SeasonObject::~SeasonObject()
{
    m_seasonSFMap.clear();
}

void SeasonObject::initSeason()
{
    for(int i = GameConst::SPRING; i <= GameConst::WINTER; i++)
    {
        Rect rect(0, i * 16, 64, 16);
        auto frame = SpriteFrame::create("testEarth.png", rect);
        char name[20];
        sprintf(name, "earth%d", i);
        SpriteFrameCache::getInstance()->addSpriteFrame(frame, name);
    }
    
    auto frame = this->getSpriteFrame(GameConst::SEASON::SPRING);
    m_currSprite = Sprite::createWithSpriteFrame(frame);
    
    frame = this->getSpriteFrame(GameConst::SEASON::SUMMER);
    m_nextSprite = Sprite::createWithSpriteFrame(frame);
    m_nextSprite->setOpacity(0);
    
    this->addChild(m_currSprite);
    this->addChild(m_nextSprite);
    
}

SpriteFrame* SeasonObject::getSpriteFrame(GameConst::SEASON season)
{
    char name[20];
    sprintf(name, "earth%d", season);
    
    return SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
}

void SeasonObject::changeSeason(GameConst::SEASON season, float dur)
{
    if (m_season == season) return;
    
    m_season = season;
    
    auto frame = this->getSpriteFrame(season);
    m_nextSprite->setSpriteFrame(frame);
    
    auto fadeInAction = FadeIn::create(dur);
    auto fadeOutAction = fadeInAction->reverse();
    
    auto callback = CallFuncN::create( CC_CALLBACK_1(SeasonObject::changeSeasonFinish, this));

    auto seq = Sequence::create(fadeInAction, callback, NULL);
    
    m_currSprite->runAction(fadeOutAction);
    m_nextSprite->runAction(seq);
}

void SeasonObject::changeSeasonFinish(Node* sender)
{
    auto nextSpriteFrame = m_nextSprite->getSpriteFrame();
    m_currSprite->setSpriteFrame(nextSpriteFrame);
    m_currSprite->setOpacity(255);
    
    m_nextSprite->setOpacity(0);
}



