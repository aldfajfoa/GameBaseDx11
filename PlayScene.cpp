#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Road.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

float num[3] = { -3.5,0,3.5 };

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), 
	hPict_(-1),pnumA(0), pnumB(0), timer_(1), intervaltimer_(0), Etimer_(1)
{
}

void PlayScene::Initialize()
{
	hPict_ = Image::Load("back.png");
	assert(hPict_ >= 0);

	Instantiate<Road>(this);
	Instantiate<Player>(this);
	player = (Player*)(FindChildObject("Player"));
}

void PlayScene::Update()
{
	intervaltimer_ += 0.5;

	if (intervaltimer_ == 250) {
		if (Etimer_ > 0.3) {
			Etimer_ -= 0.1;
		}
		intervaltimer_ = 0;
	}

	//“G‚ðo‚·ˆ—-----------
	pnumA = rand() % 3;
	pnumB = rand() % 3;
	while (pnumB == pnumA) {
		pnumB = rand() % 3;
		if (pnumB != pnumA)
			break;
	}

	timer_ -= 0.01;
	if (player->GetPalive()) {
		if (timer_ <= 0) {
			for (int i = 0; i < 2; i++) {
				if (player->GetPalive()) {
					enemy = Instantiate<Enemy>(this);
					if (i == 0)
						enemy->SetPosition(0 + num[pnumA], -2.8, 40);
					else
						enemy->SetPosition(0 + num[pnumB], -2.8, 40);
				}
			}
			timer_ = Etimer_;
		}
	}
	//---------------------------
	if (player->GetPalive() == false) {
		if (Input::IsMouseButtonDown(0))
		{
			SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
			pSM->ChangeScene(SCENE_ID::SCENE_ID_TITLE);
		}
	}
}

void PlayScene::Draw()
{
	Image::Draw(hPict_);
}

void PlayScene::Release()
{
}
