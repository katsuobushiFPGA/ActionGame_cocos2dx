#include "StatusLayer.h"

USING_NS_CC;

bool StatusLayer::init()
{
	//////////////////////////////
	// 1. 最初に親クラスの初期化を行う。
	if (!Layer::init())
	{
		return false;
	}
	// 2. 画面サイズを取得する。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 3. ラベルを作成する。
	auto labelCoin = LabelTTF::create("Coins:0", "Helvetica", 20);
	labelCoin->setColor(Color3B(0, 0, 0));
	labelCoin->setPosition(Vec2(70, visibleSize.height - 20));
	addChild(labelCoin);

	auto labelMeter = LabelTTF::create("0M", "Helvetica", 20);
	labelMeter->setPosition(Vec2(visibleSize.width - 70, visibleSize.height - 20));
	addChild(labelMeter);

	return true;
}
