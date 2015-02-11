#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:
	// cppにはidがないので、クラスのインスタンスのポインタを返すことを推奨する。
	static cocos2d::Scene* createScene();

	// init()関数は、cocos2d-iphoneでは、idを返すが、cocos2d-xはブール値を返す。
	virtual bool init();

	// static create()を自前でで実装する。
	CREATE_FUNC(PlayScene);

	static void onPlay(Ref* pSender);
};

#endif // __PLAY_SCENE_H__
