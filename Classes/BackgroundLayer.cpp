#pragma once
#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
	//////////////////////////////
	// 1. �ŏ��ɐe�N���X�̏��������s���B
	if (!Layer::init())
	{
		return false;
	}
	// 2. ��ʃT�C�Y���擾����B
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 3. ���S���v�Z����B
	auto centerpos = visibleSize / 2;

	// 4. �w�i�摜���쐬���A�ʒu�ƒ��S��ݒ肷��B
	auto spritebg = Sprite::create("playbg.png");
	spritebg->setPosition(centerpos);
	addChild(spritebg);

	return true;
}