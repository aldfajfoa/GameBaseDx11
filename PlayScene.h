#pragma once
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Road.h"
#include "Enemy.h"
#include "Player.h"

class Player;

class PlayScene :
    public GameObject
{
    float timer_;
    float intervaltimer_;
    float Etimer_;
    int ScoreTimer_;
    Enemy* enemy;
    Player* player;
    int pnumA;
    int pnumB;
    int hPict_;
    float destime;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    PlayScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    int GetpnumA() { return pnumA; }

    int GetpnumB() { return pnumB; }
};

