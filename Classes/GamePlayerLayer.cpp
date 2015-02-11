#include "GamePlayerLayer.h"

USING_NS_CC;

bool GamePlayerLayer::init()
{
	//////////////////////////////
	// 1. �ŏ��ɐe�N���X�̏��������s���B
	if (!Layer::init())
	{
		return false;
	}

	//[0]:�f�t�H���g�����G
	//[1~4]:����G
	//[5~12]:����G
	//[13~19]:�W�����v
	// �L�����N�^�\��
	SpriteFrame* pSpritesCharacter[20]; // �X�v���C�g�̐�
	const int WIDTH_SIZE = 64;      // ��̃X�v���C�g�̕�
	const int HEIGHT_SIZE =60;      // ��̃X�v���C�g�̍���
	//�uunitychan.png�v����X�v���C�g�ւ̐؂�o��
	int i = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 7; x++) {
			if (y == 0 && x == 5)break;
			if ((y == 1 || y == 2) && (x == 4))break;
			CCRect rect(float(x * WIDTH_SIZE),  // X���W
				float(y * HEIGHT_SIZE), // Y���W
				float(WIDTH_SIZE),      // ��
				float(HEIGHT_SIZE));    // ����
			pSpritesCharacter[i++] = SpriteFrame::create("UnityChan_R.png", rect);
		}
	}
	// 2. ��l���̃X�v���C�g���쐬����B
	auto Character = Sprite::create("UnityChan_R.png", 
		 Rect(0,  // X���W
			 0, // Y���W
		 float(WIDTH_SIZE),      // ��
		 float(HEIGHT_SIZE)));    // ����);
	// ��l���̈ʒu��ݒ肷��B
	Character->setPosition(Vec2(80, 85));

	// 3. �ړ��A�N�V�������쐬����B
	auto actionTo = MoveTo::create(2, Vec2(300, 85));
	Character->runAction(actionTo);
	this->addChild(Character);
	
	//����A�j���[�V�����̓o�^
	auto damage_anime = Animation::create();
	for (int i = 1; i < 5; i++) {
		damage_anime->addSpriteFrame(pSpritesCharacter[i]);
	}
	damage_anime->setDelayPerUnit(0.2f);
	damage_anime->setLoops(-1);
	damage_anime->setRestoreOriginalFrame(true);
	auto damage_anime_run = CCSequence::create(CCAnimate::create(damage_anime), NULL);

	//����A�j���[�V�����̓o�^
	auto run_anime = Animation::create();
	for (int i = 5; i < 13; i++) {
		run_anime->addSpriteFrame(pSpritesCharacter[i]);
	}
	run_anime->setDelayPerUnit(0.1f);
	run_anime->setLoops(-1);
	run_anime->setRestoreOriginalFrame(true);
	auto run_anime_run = CCSequence::create(CCAnimate::create(run_anime), NULL);

	//�A�N�V�����̎��s
//	Character->runAction(damage_anime_run);
	Character->runAction(run_anime_run);

	return true;
}