//
//  Hero.h
//  Project
//
//  Created by 史宏阳 on 1/12/15.
//
//

#ifndef __Project__Hero__
#define __Project__Hero__

#include "GameObject.h"

class Hero : public GameObject
{
public:
    Hero();
    virtual ~Hero();

    virtual bool init() override;
    CREATE_FUNC(Hero);
    
    void playAniByName(std::string name);
    
protected:
    void initAnimation();
    void initAnimation(std::string name, int startPos, int endPos, bool isRestore = true);
protected:
    const char* RES_HERO;
    
    
    
    
};

#endif /* defined(__Project__Hero__) */
