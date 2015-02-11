#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "GamePlayerLayer.h"
#include "StatusLayer.h"

USING_NS_CC;

Scene* PlayScene::createScene()
{
	// 'scene' は autorelease オブジェクト
	auto scene = Scene::create();

	// 'layer' は autorelease オブジェクト
	auto layer = PlayScene::create();

	// レイヤーをシーンの子として追加する。
	scene->addChild(layer);

	// シーンを返す。
	return scene;
}

bool PlayScene::init()
{
	//////////////////////////////
	// 1. 最初に親クラスの初期化を行う。
	if (!Layer::init())
	{
		return false;
	}
	// 2. ３つのレイヤーを追加する。
	auto backgroundLayer = BackgroundLayer::create();
	this->addChild(backgroundLayer);
	auto gameplayLayer = GamePlayerLayer::create();
	addChild(gameplayLayer);
	auto statusLayer = StatusLayer::create();
	addChild(statusLayer);
	return true;
}
