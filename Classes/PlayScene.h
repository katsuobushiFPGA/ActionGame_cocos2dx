#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:
	// cpp�ɂ�id���Ȃ��̂ŁA�N���X�̃C���X�^���X�̃|�C���^��Ԃ����Ƃ𐄏�����B
	static cocos2d::Scene* createScene();

	// init()�֐��́Acocos2d-iphone�ł́Aid��Ԃ����Acocos2d-x�̓u�[���l��Ԃ��B
	virtual bool init();

	// static create()�����O�łŎ�������B
	CREATE_FUNC(PlayScene);

	static void onPlay(Ref* pSender);
};

#endif // __PLAY_SCENE_H__
