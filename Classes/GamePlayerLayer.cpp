#include "GamePlayerLayer.h"

USING_NS_CC;

bool GamePlayerLayer::init()
{
	//////////////////////////////
	// 1. 最初に親クラスの初期化を行う。
	if (!Layer::init())
	{
		return false;
	}

	//[0]:デフォルト立ち絵
	//[1~4]:やられ絵
	//[5~12]:走る絵
	//[13~19]:ジャンプ
	// キャラクタ表示
	SpriteFrame* pSpritesCharacter[20]; // スプライトの数
	const int WIDTH_SIZE = 64;      // 一つのスプライトの幅
	const int HEIGHT_SIZE =60;      // 一つのスプライトの高さ
	//「unitychan.png」からスプライトへの切り出し
	int i = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 7; x++) {
			if (y == 0 && x == 5)break;
			if ((y == 1 || y == 2) && (x == 4))break;
			CCRect rect(float(x * WIDTH_SIZE),  // X座標
				float(y * HEIGHT_SIZE), // Y座標
				float(WIDTH_SIZE),      // 幅
				float(HEIGHT_SIZE));    // 高さ
			pSpritesCharacter[i++] = SpriteFrame::create("UnityChan_R.png", rect);
		}
	}
	// 2. 主人公のスプライトを作成する。
	auto Character = Sprite::create("UnityChan_R.png", 
		 Rect(0,  // X座標
			 0, // Y座標
		 float(WIDTH_SIZE),      // 幅
		 float(HEIGHT_SIZE)));    // 高さ);
	// 主人公の位置を設定する。
	Character->setPosition(Vec2(80, 85));

	// 3. 移動アクションを作成する。
	auto actionTo = MoveTo::create(2, Vec2(300, 85));
	Character->runAction(actionTo);
	this->addChild(Character);
	
	//やられアニメーションの登録
	auto damage_anime = Animation::create();
	for (int i = 1; i < 5; i++) {
		damage_anime->addSpriteFrame(pSpritesCharacter[i]);
	}
	damage_anime->setDelayPerUnit(0.2f);
	damage_anime->setLoops(-1);
	damage_anime->setRestoreOriginalFrame(true);
	auto damage_anime_run = CCSequence::create(CCAnimate::create(damage_anime), NULL);

	//走るアニメーションの登録
	auto run_anime = Animation::create();
	for (int i = 5; i < 13; i++) {
		run_anime->addSpriteFrame(pSpritesCharacter[i]);
	}
	run_anime->setDelayPerUnit(0.1f);
	run_anime->setLoops(-1);
	run_anime->setRestoreOriginalFrame(true);
	auto run_anime_run = CCSequence::create(CCAnimate::create(run_anime), NULL);

	//アクションの実行
//	Character->runAction(damage_anime_run);
	Character->runAction(run_anime_run);

	return true;
}