//
//  WorldMap.cpp
//  Project
//
//  Created by shihongyang on 15/1/13.
//
//

#include "WorldMap.h"

USING_NS_CC;

WorldMap::WorldMap()
: m_map(nullptr)
, m_map_file("")
{
    
}

WorldMap::~WorldMap()
{
}

bool WorldMap::init()
{
    
    return true;
}

void WorldMap::setMapByTmx(std::string tmxFile)
{
    m_map = TMXTiledMap::create(tmxFile);
    this->addChild(m_map);
}