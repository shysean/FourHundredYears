//
//  TestBaseScene.cpp
//  Project
//
//  Created by 史宏阳 on 1/8/15.
//
//

#include "TestBaseScene.h"
#include "TestScene.h"

USING_NS_CC;

TestBaseScene::TestBaseScene()
{

}

TestBaseScene::~TestBaseScene()
{
    m_menuItemList.clear();
}

bool TestBaseScene::initMenu()
{
    // Create Test Menu
    initTestMethod();
    auto menu = Menu::createWithArray(m_menuItemList);
    menu->alignItemsVertically();
    this->addChild(menu);
    
    
    Size winSize = Director::getInstance()->getWinSize();
    
    auto button = ui::Button::create();
    button->setTitleFontName("Arial");
    button->setTitleFontSize(30);
    button->setTitleText("Back");
    button->setAnchorPoint(Vec2(1,0));
    button->setPosition(Vec2(winSize.width - 5, 5));
    button->addClickEventListener([=](Ref*){
        auto scene = TestScene::create();
        Director::getInstance()->replaceScene(scene);});
    this->addChild(button);
    
    return true;
}

void TestBaseScene::addTestMenuItem(cocos2d::MenuItem *menuItem)
{
    m_menuItemList.pushBack(menuItem);
}
