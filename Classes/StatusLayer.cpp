#include "StatusLayer.h"

USING_NS_CC;

bool StatusLayer::init()
{
	//////////////////////////////
	// 1. �ŏ��ɐe�N���X�̏��������s���B
	if (!Layer::init())
	{
		return false;
	}
	// 2. ��ʃT�C�Y���擾����B
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 3. ���x�����쐬����B
	auto labelCoin = LabelTTF::create("Coins:0", "Helvetica", 20);
	labelCoin->setColor(Color3B(0, 0, 0));
	labelCoin->setPosition(Vec2(70, visibleSize.height - 20));
	addChild(labelCoin);

	auto labelMeter = LabelTTF::create("0M", "Helvetica", 20);
	labelMeter->setPosition(Vec2(visibleSize.width - 70, visibleSize.height - 20));
	addChild(labelMeter);

	return true;
}
