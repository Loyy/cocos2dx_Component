//
//  EntranceScene.cpp
//  UmengGame
//
//  Created by wangfei on 16/4/6.
//
//

#include "AppScence.h"
#include "AnalyticsHome.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* AppScence::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    AppScence *layer = AppScence::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AppScence::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    Label *pLabel = Label::createWithTTF("UM-Cocos2dx-Social", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);

   
    // 授权某平台

    MenuItemImage *pCloseItem = MenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                           CC_CALLBACK_1(AppScence::menuCloseCallback, this));
    
    pCloseItem->setPosition(Vec2(origin.x + visibleSize.width - pCloseItem->getContentSize().width ,
                                origin.y + pCloseItem->getContentSize().height));
   
    Menu* pMenu = Menu::create();
  
   
    pMenu->setPosition(Size::ZERO);
    this->addChild(pMenu, 1);
    return true;
}

void AppScence::gotoApp(Ref* pSender) {
   
}
void AppScence::gotoGame(Ref* pSender) {
  
}

void AppScence::menuCloseCallback(Ref* pSender)
{
    TransitionScene * reScene = NULL;
    Scene * s = AppScence::scene();
    float t = 1.2f;
    
    reScene = TransitionJumpZoom ::create(t , s);
    Director::getInstance()->replaceScene(reScene);

   }

