#pragma once
#include "Engine/GameObject.h"
#include "Road.h"
#include "Engine/Text.h"
#include "PlayScene.h"]

struct framePos {
    double x;
    double y;
};

class Player :
    public GameObject
{
    int hModel_;
    int ExPict_;
    int OverPict_;
    float speed_;
    Transform pPos;
    Transform tmp;
    Transform exTra;
    XMFLOAT3 cameraP;
    Road* road;
    int Score;
    Text* ScoreTime;
    PlayScene* palive;
    bool Palive;
    bool isOver;
    bool isExp;
    int shake;
    int exflame;
    float exTime;
    //1024,615  204.8*5  205*3
    framePos framenum[15] = { { 0,0 },   {204.8,0 },  {204.8 * 2, 0 },  { 204.8 * 3,0 },  { 204.8 * 4,0 },
                              { 0,205 }, {204.8,205}, {204.8 * 2, 205 },{ 204.8 * 3,205 },{ 204.8 * 4,205 },
                              { 0,205*2 }, {204.8,205 * 2}, {204.8 * 2, 205 * 2 },{ 204.8 * 3,205 * 2 },{ 204.8 * 4,205 * 2 }, };
    int anime;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    Player(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����ɓ�������
    //�����FpTarget ������������
    void OnCollision(GameObject* pTarget) override;

    bool GetPalive() { return Palive; }
};
