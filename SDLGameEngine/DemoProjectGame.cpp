#include "DemoProjectGame.h"
#include "Scene1.h"
#include "SpriteRenderer.h"
#include "Sprite.h"
#include "Rect.h"
#include "RenderModule.h"


DemoProjectGame::DemoProjectGame()
{
}


DemoProjectGame::~DemoProjectGame()
{
}

void DemoProjectGame::Awake()
{
	RenderModule::numberOfLayers = 2;
	AddPrefab("Enemy", std::bind(&DemoProjectGame::EnemyPrefab, this, std::placeholders::_1));
}

void DemoProjectGame::Setup()
{
	SetScene(new Scene1());
}

void DemoProjectGame::EnemyPrefab(GameObject* enemy)
{
	GameObject* enemyGraphic = Instantiate("EnemyGraphic", 0, 0, 90);
	enemyGraphic->transform->SetParentRelative(enemy->transform);
	enemyGraphic->transform->SetAbsoluteScale(Vector2(0.3f, 0.3f));
	Sprite* enemyTank = new Sprite("Assets/tanks_3.png", new Rect(350, 250, 200, 150));
	enemyGraphic->AddComponent(new SpriteRenderer(enemyTank));
}