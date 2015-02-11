#pragma once
#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
	//////////////////////////////
	// 1. 最初に親クラスの初期化を行う。
	if (!Layer::init())
	{
		return false;
	}
	// 2. 画面サイズを取得する。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 3. 中心を計算する。
	auto centerpos = visibleSize / 2;

	// 4. 背景画像を作成し、位置と中心を設定する。
	auto spritebg = Sprite::create("playbg.png");
	spritebg->setPosition(centerpos);
	addChild(spritebg);

	return true;
}