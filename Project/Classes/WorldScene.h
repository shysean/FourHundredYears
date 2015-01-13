//
//  WorldScene.h
//  Project
//
//  Created by 史宏阳 on 1/10/15.
//
//

#ifndef __Project__WorldScene__
#define __Project__WorldScene__

#include "cocos2d.h"

class WorldMap;

class WorldScene : public cocos2d::Scene
{
public:
    WorldScene();
    virtual ~WorldScene();
    
//    CREATE_FUNC(WorldScene);
    
//    virtual bool init() override;
    virtual void onEnter() override;
    
protected:
    WorldMap* m_map;
};

#endif /* defined(__Project__WorldScene__) */
