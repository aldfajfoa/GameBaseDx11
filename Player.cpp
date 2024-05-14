#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Road.h"
#include "Engine/SphereCollider.h"
#include "Engine/Camera.h"
#include "Engine/Image.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1),speed_(0.3), Palive(true), 
	shake(0),exflame(0),ExPict_(-1), OverPict_(-1),isOver(false),isExp(false),exTime(10),Score(0)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	ExPict_ = Image::Load("Explosion.png");
	assert(ExPict_ >= 0);
	OverPict_ = Image::Load("OVER.png");
	assert(OverPict_ >= 0);

	road = (Road*)FindObject("Road");
	pPos.position_ = road->GetRoadPos().position_;
	pPos.position_.y -=2;
	pPos.scale_ = { 3.5,3.5,3.5 };
	SphereCollider* Pcollision = new SphereCollider({0,0,-0.6}, 1.4f);
	AddCollider(Pcollision);
	ScoreTime = new Text;
	ScoreTime->Initialize();
	cameraP = Camera::GetPosition();
	anime = 0;
	exTra.scale_ = { 30,20,20 };
}

void Player::Update()
{
	if (Palive) {
		Score += 1;

		tmp.position_ = pPos.position_;
		if (Input::IsKey(DIK_LEFT)) {
			pPos.position_.x -= speed_;
			pPos.rotate_.z = 30;
		}
		else {
			pPos.rotate_.z = 0;
		}

		if (Input::IsKey(DIK_RIGHT)) {
			pPos.position_.x += speed_;
			pPos.rotate_.z = -30;
		}
		else {
			pPos.position_.z = 0;
		}

		if (pPos.position_.x + 1 >= 5) {
			pPos.position_.x = tmp.position_.x;
		}
		if (pPos.position_.x - 1 <= -5) {
			pPos.position_.x = tmp.position_.x;
		}
	}

	if (Palive == false) {
		pPos.rotate_.y += 60;
		pPos.rotate_.x += 60;
		pPos.rotate_.z += 60;
		if (shake == 0) {
			Camera::SetPosition(XMFLOAT3(cameraP.x, cameraP.y, cameraP.z + 0.2));
			shake++;
		}
		else {
			Camera::SetPosition(XMFLOAT3(cameraP.x, cameraP.y, cameraP.z - 0.2));
			shake = 0;
		}
		if (isOver == false) {
			exTime -= 0.1;
		}
		if (exTime <= 0) {
			isExp = true;
			exTime = 1;
		}
	}

	Image::SetRect(ExPict_, framenum[anime].x,framenum[anime].y, 204.8, 205);

	if (isExp) {
		if (exflame == 0) {
			anime++;
			if (anime == 15) {
				anime = 0;
				isExp = false;
			}

			if (anime == 6) {
				isOver = true;
			}
			exflame++;
		}
		else if (exflame == 1) {
			exflame++;
		}
		else {
			exflame = 0;
		}
	}
}

void Player::Draw()
{
	transform_ = pPos;
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	if (isOver) {
		Image::Draw(OverPict_);
		ScoreTime->Draw(550, 430, Score*1000);
	}
	if (isExp) {
		Image::SetTransform(ExPict_, exTra);
		Image::Draw(ExPict_);
	}
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		Palive = false;
	}
}