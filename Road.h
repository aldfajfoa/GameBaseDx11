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
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    Road(GameObject* parent);

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    Transform GetRoadPos() { return roadPos; }
};

