#include "Enemy.h"
#include "Engine/Model.h"
#include "PlayScene.h"
#include "Road.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1), speed_(0.6)
{
}

void Enemy::Initialize()
{
	en = (PlayScene*)GetParent();
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);

	transform_.rotate_.y = 180;
	transform_.scale_ = {4,4,4};

	SphereCollider* Ecollision = new SphereCollider({ 0, 1.4, -1 }, 1.3f);
	AddCollider(Ecollision);
}

void Enemy::Update()
{
	transform_.position_.z -= speed_;

	if (transform_.position_.z <= -10) {
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}