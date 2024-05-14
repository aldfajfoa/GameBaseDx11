#pragma once
#include "Engine/GameObject.h"

class PlayScene;

class Enemy :
    public GameObject
{
    PlayScene* en;
    int hModel_;
    float speed_;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Enemy(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};


