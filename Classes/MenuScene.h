#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
	// cppにはidがないので、クラスのインスタンスのポインタを返すことを推奨する。
	static cocos2d::Scene* createScene();

	// init()関数は、cocos2d-iphoneでは、idを返すが、cocos2d-xはブール値を返す。
	virtual bool init();

	// static create()を自前でで実装する。
	CREATE_FUNC(MenuScene);

	static void onPlay(Ref* pSender);
};

#endif // __MENU_SCENE_H__
