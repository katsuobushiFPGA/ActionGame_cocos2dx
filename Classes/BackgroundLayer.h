#ifndef __BG_LAYER_H__
#define __BG_LAYER_H__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
	// init()関数は、cocos2d-iphoneでは、idを返すが、cocos2d-xはブール値を返す。
	virtual bool init();

	// static create()を自前でで実装する。
	CREATE_FUNC(BackgroundLayer);

};

#endif // __BG_LAYER_H__
