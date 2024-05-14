#include "GameOver.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

GameOver::GameOver(GameObject* parent)
	:GameObject(parent, "GameOver")
{
}

void GameOver::Initialize()
{
	hPict_ = Image::Load("OVER.png");
	assert(hPict_ >= 0);
}

void GameOver::Update()
{
	if (Input::IsMouseButtonDown(0))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_TITLE);
	}
}

void GameOver::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOver::Release()
{
}
