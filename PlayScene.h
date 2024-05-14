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
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    PlayScene(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    int GetpnumA() { return pnumA; }

    int GetpnumB() { return pnumB; }
};

