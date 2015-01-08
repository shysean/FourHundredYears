//
//  TestScene.h
//  Project
//
//  Created by shihongyang on 15/1/8.
//
//

#ifndef __Project__TestScene__
#define __Project__TestScene__

#include "cocos2d.h"
#include "CocosGUI.h"

#define CREATE_CONTROLLER(varTitle, varClassName)    \
new Controller(varTitle, [](){return varClassName::create();})

class TestBaseScene;

typedef struct _Controller{
    _Controller(const char *test_name, std::function<TestBaseScene*()> callback)
    {
        this->test_name = test_name;
        this->callback = callback;
    }
    const char *test_name;
    std::function<TestBaseScene*()> callback;
} Controller;


class TestScene : public cocos2d::Scene
{
public:
    TestScene();
    virtual ~TestScene();
    
    CREATE_FUNC(TestScene)
    
    virtual bool init() override;
    
    void initController();
    
protected:
    const int MENUITEM_HEIGHT = 40;
    const int FONT_SIZE = 30;
    
    std::vector<Controller*> m_controller;
    int m_testCaseNumber;
};

#endif /* defined(__Project__TestScene__) */
