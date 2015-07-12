#include "Hero.h"
#include "MainScene.h"
USING_NS_CC;
Hero::Hero()
{
	initWithSpriteFrameName("1.png");
        stopAllActions();
	this->runAction(moving());
}



RepeatForever* Hero::moving()
{
	
	cocos2d::Vector<cocos2d::SpriteFrame *> frames;
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();

	char file[100] = { 0 };

	for (int i = 0; i < 3; i++) {
		sprintf(file, "%d.png", i + 1);
		SpriteFrame *frame = frameCache->getSpriteFrameByName(file);
		frames.pushBack(frame);
	}

	Animation *animation = Animation::createWithSpriteFrames(frames, 0.15f);
	Animate *animate = Animate::create(animation);

	RepeatForever *repeat = RepeatForever::create(animate);
	return repeat;
}


void Hero::up(){

    auto jmp = MoveBy::create(0.25,Vec2(10,0));
    //stopAllActions();

    this->runAction(jmp);
}

void Hero::back(){
    auto jmp = MoveBy::create(0.25,Vec2(-10,0));
   // stopAllActions();
    this->runAction(jmp);
}

void Hero::jump(){
    auto jmp = JumpBy::create(0.25,Vec2(0,0),30,1);
    this->runAction(jmp);

}



