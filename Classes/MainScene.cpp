
#include "MainScene.h"


USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();
    
	auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
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
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
										   CC_CALLBACK_1(MainScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

     hero = new Hero();
	hero->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(hero);

    auto keyListener = EventListenerKeyboard::create();

    keyListener->onKeyPressed = CC_CALLBACK_2(MainScene::keyboardHandler,this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener,this);
    return true;
}


void MainScene::keyboardHandler(EventKeyboard::KeyCode keyCode, Event* event){

   switch(keyCode){
   case EventKeyboard::KeyCode::KEY_A:{
       hero->back();
       break;
   }
   case EventKeyboard::KeyCode::KEY_D:{
       hero->up();
       break;
   }
   case EventKeyboard::KeyCode::KEY_SPACE:{
       hero->jump();
       break;
   }
   }
}



void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
