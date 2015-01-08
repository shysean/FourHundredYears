//
//  TestScene.cpp
//  Project
//
//  Created by shihongyang on 15/1/8.
//
//

#include "TestScene.h"

USING_NS_CC;


TestScene::TestScene(){};
TestScene::~TestScene(){};


bool TestScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    // Create the scrollview by VERTICAL
    ui::ScrollView* scrollView = ui::ScrollView::create();
    scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
    scrollView->setContentSize(winSize);
    scrollView->setInnerContainerSize(Size(winSize.width, winSize.height * 3));
    scrollView->setBounceEnabled(false);
    this->addChild(scrollView);

    auto innerLayer = LayerGradient::create(Color4B::GREEN, Color4B::RED);
    innerLayer->setContentSize(scrollView->getInnerContainerSize());
    scrollView->addChild(innerLayer);
    

    
    return true;
}

Menu* TestScene::createTestCaseMenu()
{
    auto menu = Menu::create();
    
    
    return menu;
}