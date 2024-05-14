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
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Player(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //何かに当たった
    //引数：pTarget 当たった相手
    void OnCollision(GameObject* pTarget) override;

    bool GetPalive() { return Palive; }
};
