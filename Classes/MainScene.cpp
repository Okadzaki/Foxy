
#include "MainScene.h"
#include "Hero.h"


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


	Hero *hero = new Hero();
	hero->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(hero);

	auto eventListener = EventListenerKeyboard::create();
	eventListener->onKeyPressed = [] (EventKeyboard::KeyCode keyCode, Event* event){
		Vec2 loc = event->getCurrentTarget()->getPosition();
		
			
			switch (keyCode){
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			case EventKeyboard::KeyCode::KEY_A:
				event->getCurrentTarget()->setPosition(loc.x-5, loc.y);
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			case EventKeyboard::KeyCode::KEY_D:
				event->getCurrentTarget()->setPosition(loc.x+5, loc.y);
				break;
			case EventKeyboard::KeyCode::KEY_SPACE:{
				event->getCurrentTarget()->setPosition(loc.x, loc.y+10);
				break;
			}
			}
	};
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, hero);


	this->scheduleUpdate();

    return true;
}


void MainScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

}
void MainScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{

}



void MainScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
