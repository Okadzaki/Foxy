#include "Hero.h"
#include "MainScene.h"
USING_NS_CC;
Hero::Hero()
{
	initWithSpriteFrameName("1.png");
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



