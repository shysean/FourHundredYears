//
//  SeasonObject.h
//  Project
//
//  Created by 史宏阳 on 2/4/15.
//
//

#ifndef __Project__SeasonObject__
#define __Project__SeasonObject__

#include "GameObject.h"
#include "GameConst.h"

class SeasonObject : public GameObject
{
public:
    SeasonObject();
    virtual ~SeasonObject();
    
    virtual void initSeason();
    
    void changeSeason(GameConst::SEASON season, float dur);
    void changeSeasonFinish(Node* sender);

    CC_SYNTHESIZE(cocos2d::Sprite*, m_currSprite, CurrSprite);
    CC_SYNTHESIZE(cocos2d::Sprite*, m_nextSprite, NextSprite);
    
    CC_SYNTHESIZE(GameConst::SEASON, m_season, Season);
    
protected:
    cocos2d::SpriteFrame* getSpriteFrame(GameConst::SEASON season);

protected:
    cocos2d::Map<std::string, cocos2d::SpriteFrame*> m_seasonSFMap;

};

#endif /* defined(__Project__SeasonObject__) */
