#ifndef __BG_LAYER_H__
#define __BG_LAYER_H__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
	// init()�֐��́Acocos2d-iphone�ł́Aid��Ԃ����Acocos2d-x�̓u�[���l��Ԃ��B
	virtual bool init();

	// static create()�����O�łŎ�������B
	CREATE_FUNC(BackgroundLayer);

};

#endif // __BG_LAYER_H__
