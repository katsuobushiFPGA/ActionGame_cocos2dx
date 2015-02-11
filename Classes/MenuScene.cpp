#pragma once
#include "MenuScene.h"
#include "PlayScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' は autorelease オブジェクト
	auto scene = Scene::create();

	// 'layer' は autorelease オブジェクト
	auto layer = MenuScene::create();

	// レイヤーをシーンの子として追加する。
	scene->addChild(layer);

	// シーンを返す。
	return scene;
}

// "init" では、インスタスの初期化を行う。
bool MenuScene::init()
{
	//////////////////////////////
	// 1. 最初に親クラスの初期化を行う。
	if (!Layer::init())
	{
		return false;
	}
	// 2. 画面サイズを取得する。
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 3. 中心を計算する。
	auto centerpos = visibleSize / 2;

	// 4. 背景画像を作成し、位置と中心を設定する。
	auto spritebg = Sprite::create("bg.png");
	spritebg->setPosition(centerpos);
	this->addChild(spritebg);

	// 5. メニューのフォントのサイズを設定する。
	MenuItemFont::setFontSize(60);

	// 6. メニューを作成し、onPlayイベントコールバック関数を設定する。
	auto menuItemPlay = MenuItemImage::create(
		"btn_start_unclicked.png",
		"btn_start_clicked.png",
		CC_CALLBACK_0(MenuScene::onPlay, this));
	auto menu = Menu::create(menuItemPlay, NULL);
	addChild(menu);

	return true;
}

// メニュー項目が押された場合のコールバック関数。
void MenuScene::onPlay(Ref* pSender)
{
	//  log("==onPlay clicked");
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}