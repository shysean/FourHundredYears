//
//  TestScene.cpp
//  Project
//
//  Created by shihongyang on 15/1/8.
//
//

#include "TestScene.h"
#include "TMXMapTest.h"
#include "HeroTest.h"

USING_NS_CC;

TestScene::TestScene()
: m_testCaseNumber(0)
{
    initController();
};

TestScene::~TestScene()
{
    std::vector <Controller*>::iterator iter;
    iter = m_controller.begin();
    while (iter != m_controller.end())
    {
        delete *iter;
        iter = m_controller.erase(iter);
    }
    std::vector<Controller*>(m_controller).swap(m_controller);
};


void TestScene::initController()
{
    m_controller.push_back(CREATE_CONTROLLER("TMXMapTest", TMXMapTest));
    m_controller.push_back(CREATE_CONTROLLER("HeroTest", HeroTest));

    m_testCaseNumber = m_controller.size();
}

bool TestScene::init()
{
    Size winSize = Director::getInstance()->getWinSize();
    Size menuSize = Size(winSize.width, m_testCaseNumber * MENUITEM_HEIGHT);
    if(menuSize.height <= winSize.height) menuSize = winSize;

    // Create the scrollview by VERTICAL
    ui::ScrollView* scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setContentSize(winSize);
    scrollView->setBounceEnabled(true);
    this->addChild(scrollView);

    // Create test menu
    auto menu = Menu::create();
    menu->setContentSize(menuSize);
    scrollView->setInnerContainerSize(menuSize);
    scrollView->addChild(menu);
    
    for (int i = 0; i < m_testCaseNumber; i++) {
        auto label = Label::createWithSystemFont(m_controller[i]->test_name, "Arial", FONT_SIZE);
        auto callback = [&](Ref *sender) {
            auto menuItem = static_cast<MenuItemLabel*>(sender);
            int index = menuItem->getTag();
            
            auto scene = m_controller[index]->callback();
            scene->autorelease();
            Director::getInstance()->replaceScene(scene);
        };
        auto item = MenuItemLabel::create(label, callback);
        
        item->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
        item->setPosition(Vec2(menuSize.width * 0.5, menuSize.height - MENUITEM_HEIGHT * i));
        item->setTag(i);
        
        menu->addChild(item);
    }
    
    menu->ignoreAnchorPointForPosition(false);
    menu->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    menu->setPosition(menuSize.width * 0.5, menuSize.height * 0.5);
    
    return true;
}