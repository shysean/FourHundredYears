//
//  WorldMap.h
//  Project
//
//  Created by shihongyang on 15/1/13.
//
//

#ifndef __Project__WorldMap__
#define __Project__WorldMap__

#include "cocos2d.h"
#include "GameObject.h"

class WorldMap : public GameObject
{
public:
    WorldMap();
    virtual ~WorldMap();
    
    bool init() override;
    CREATE_FUNC(WorldMap);
    
    void setMapByTmx(std::string tmxFile);
    
protected:
    std::string m_map_file;
    cocos2d::TMXTiledMap* m_map;
    
};

#endif /* defined(__Project__WorldMap__) */
