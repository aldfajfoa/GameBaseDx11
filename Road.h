#pragma once
#include "Engine/GameObject.h"
#include "Tree.h"

class Road :
    public GameObject
{
    int hModel_;
    float treetimer_;
    Transform roadPos;
    Tree* tree;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Road(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    Transform GetRoadPos() { return roadPos; }
};

