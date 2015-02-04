//
//  AniTest.h
//  Project
//
//  Created by 史宏阳 on 2/4/15.
//
//

#ifndef __Project__AniTest__
#define __Project__AniTest__

#include "TestBaseScene.h"
#include "GameConst.h"

class SeasonObject;

class AniTest : public TestBaseScene
{
public:
    AniTest();
    virtual ~AniTest();
    virtual void initTestMethod();
    
    void testChange();
    void testSeasonObject();
    void testChangeSeason();
    
protected:
    SeasonObject* m_seasonObject;
    int m_season;
};


#endif /* defined(__Project__AniTest__) */
