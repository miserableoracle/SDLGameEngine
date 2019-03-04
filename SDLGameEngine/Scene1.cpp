#include "Scene1.h"
#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "PlayerControls.h"
#include "Game.h"
#include <time.h>
#include "Sprite.h"

Scene1::Scene1()
{
}


Scene1::~Scene1()
{
}

void Scene1::Setup()
{
	GameObject* player = Instantiate("Player", Camera::width / 2, Camera::height / 2);
	GameObject* playerGraphic = Instantiate("PlayerGraphic", 0, 0, 90 );
	playerGraphic->transform->SetParentRelative(player->transform);
	playerGraphic->transform->SetAbsoluteScale(Vector2(0.1f, 0.1f));
	Sprite* playerSprite = new Sprite("Assets/Tank.png");
	playerGraphic->AddComponent(new SpriteRenderer(playerSprite, 1));
	PlayerControls* control = new PlayerControls();
	control->speed = 500;
	player->AddComponent(control);
	for (int i = 0; i < 100; i++)
	{
		Instantiate(game->Prefab("Enemy"), rand() % Camera::width, rand() % Camera::height);
	}
}
