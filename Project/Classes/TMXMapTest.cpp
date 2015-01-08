//
//  TMXMapTest.cpp
//  Project
//
//  Created by 史宏阳 on 1/8/15.
//
//

#include "TMXMapTest.h"

TMXMapTest::TMXMapTest()
{
    CCLOG("TMXMapTest ctor");
}

TMXMapTest::~TMXMapTest()
{
    
}

bool TMXMapTest::init()
{
    if ( !TestBaseScene::init() )
    {
        return false;
    }
    return true;
}

void TMXMapTest::initTestMethod()
{
    ADD_TEST_METHOD(testFunction);
}

void TMXMapTest::testFunction()
{
    CCLOG("testFunction");
}
