//
//  TestBaseScene.h
//  Project
//
//  Created by 史宏阳 on 1/8/15.
//
//

#ifndef __Project__TestBaseScene__
#define __Project__TestBaseScene__

#include "cocos2d.h"
#include "CocosGUI.h"

USING_NS_CC;

// @param __vectorOfMenu__  Vector<cocos2d::MenuItem *>
// @param __funcName__      callback method name also as title
#define ADD_TEST_METHOD(__funcName__) \
auto __funcName__##Label = Label::createWithSystemFont(#__funcName__, "Arial", 30); \
auto __funcName__##MenuItem = MenuItemLabel::create(__funcName__##Label, [=](Ref * sender){ __funcName__();}); \
addTestMenuItem(__funcName__##MenuItem);\

class TestBaseScene : public cocos2d::Scene
{
public:
    TestBaseScene();
    virtual ~TestBaseScene();
    virtual void initTestMethod() = 0;
    virtual bool init() override;
    
protected:
    void addTestMenuItem(cocos2d::MenuItem *menuItem);

protected:
    
    cocos2d::Vector<cocos2d::MenuItem *> m_menuItemList;
    cocos2d::Menu* m_testMenu;
};

#endif /* defined(__Project__TestBaseScene__) */
