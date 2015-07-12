#ifndef __HERO_SCENE_H__
#define __HERO_SCENE_H__


#include "cocos2d.h"


class Hero:public cocos2d::Sprite
{
private:
	cocos2d::RepeatForever* moving();


public:
    void up();
    void back();
    void jump();
	Hero();
};

#endif // __HERO_SCENE_H__
