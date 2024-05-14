#include "Tree.h"
#include "Engine/Model.h"

Tree::Tree(GameObject* parent)
	:GameObject(parent, "Tree"), hModel_(-1), speed_(0.6)
{
}

void Tree::Initialize()
{
	hModel_ = Model::Load("Model\\Tree.fbx");
	assert(hModel_ >= 0);
	transform_.position_.y -= 3;
	transform_.position_.x -= 6.3;
	transform_.scale_ = { 3,3,3 };
}

void Tree::Update()
{
	transform_.position_.z -= speed_;

	if (transform_.position_.z <= -10) {
		KillMe();
	}
}

void Tree::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tree::Release()
{
}
