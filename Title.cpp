#include "Title.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Image.h"
#include "Engine/Camera.h"

Title::Title(GameObject* parent)
	:GameObject(parent, "Title")
{
}

void Title::Initialize()
{
	hPict_ = Image::Load("TITLE.png");
	assert(hPict_ >= 0);
}

void Title::Update()
{

	if (Input::IsMouseButtonDown(0))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void Title::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void Title::Release()
{
}
