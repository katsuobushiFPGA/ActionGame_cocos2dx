#pragma once
#include "MenuScene.h"
#include "PlayScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' �� autorelease �I�u�W�F�N�g
	auto scene = Scene::create();

	// 'layer' �� autorelease �I�u�W�F�N�g
	auto layer = MenuScene::create();

	// ���C���[���V�[���̎q�Ƃ��Ēǉ�����B
	scene->addChild(layer);

	// �V�[����Ԃ��B
	return scene;
}

// "init" �ł́A�C���X�^�X�̏��������s���B
bool MenuScene::init()
{
	//////////////////////////////
	// 1. �ŏ��ɐe�N���X�̏��������s���B
	if (!Layer::init())
	{
		return false;
	}
	// 2. ��ʃT�C�Y���擾����B
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 3. ���S���v�Z����B
	auto centerpos = visibleSize / 2;

	// 4. �w�i�摜���쐬���A�ʒu�ƒ��S��ݒ肷��B
	auto spritebg = Sprite::create("bg.png");
	spritebg->setPosition(centerpos);
	this->addChild(spritebg);

	// 5. ���j���[�̃t�H���g�̃T�C�Y��ݒ肷��B
	MenuItemFont::setFontSize(60);

	// 6. ���j���[���쐬���AonPlay�C�x���g�R�[���o�b�N�֐���ݒ肷��B
	auto menuItemPlay = MenuItemImage::create(
		"btn_start_unclicked.png",
		"btn_start_clicked.png",
		CC_CALLBACK_0(MenuScene::onPlay, this));
	auto menu = Menu::create(menuItemPlay, NULL);
	addChild(menu);

	return true;
}

// ���j���[���ڂ������ꂽ�ꍇ�̃R�[���o�b�N�֐��B
void MenuScene::onPlay(Ref* pSender)
{
	//  log("==onPlay clicked");
	auto playScene = PlayScene::createScene();
	Director::getInstance()->replaceScene(playScene);
}