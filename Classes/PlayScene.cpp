#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "GamePlayerLayer.h"
#include "StatusLayer.h"

USING_NS_CC;

Scene* PlayScene::createScene()
{
	// 'scene' �� autorelease �I�u�W�F�N�g
	auto scene = Scene::create();

	// 'layer' �� autorelease �I�u�W�F�N�g
	auto layer = PlayScene::create();

	// ���C���[���V�[���̎q�Ƃ��Ēǉ�����B
	scene->addChild(layer);

	// �V�[����Ԃ��B
	return scene;
}

bool PlayScene::init()
{
	//////////////////////////////
	// 1. �ŏ��ɐe�N���X�̏��������s���B
	if (!Layer::init())
	{
		return false;
	}
	// 2. �R�̃��C���[��ǉ�����B
	auto backgroundLayer = BackgroundLayer::create();
	this->addChild(backgroundLayer);
	auto gameplayLayer = GamePlayerLayer::create();
	addChild(gameplayLayer);
	auto statusLayer = StatusLayer::create();
	addChild(statusLayer);
	return true;
}
