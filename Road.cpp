#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

Road::Road(GameObject* parent) 
	:GameObject(parent, "Road"), hModel_(-1), treetimer_(0)
{
}

void Road::Initialize()
{
	hModel_ = Model::Load("Model\\Road.fbx");
	assert(hModel_ >= 0);

	roadPos.scale_ = { 30,30,100 };
	roadPos.rotate_.y = 180;
}

void Road::Update()
{
	treetimer_ -= 0.05;

	if (treetimer_ <= 0) {
		for (int i = 0; i < 2; i++) {
			tree = Instantiate<Tree>(this);
			if (i == 0)
				tree->SetPosition(0 - 6.3, -3, 40);
			else
				tree->SetPosition(0 + 6.3, -3, 40);
		}
		treetimer_ = 1;
	}
}

void Road::Draw()
{
	Model::SetTransform(hModel_,roadPos);
	Model::Draw(hModel_);
}

void Road::Release()
{
}
