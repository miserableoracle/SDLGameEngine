#include "Scene1.h"
#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "SpriteRenderer.h"


Scene1::Scene1()
{
}


Scene1::~Scene1()
{
}

void Scene1::Setup()
{
	GameObject* player = Instantiate("Player", Vector2(Camera::width / 2, Camera::height / 2));
	GameObject* playerGraphic = Instantiate("PlayerGraphic", 0, 0);
	playerGraphic->transform->SetParentRelative(player->transform);
	SpriteRenderer* tankRenderer = new SpriteRenderer("Assets/Tank.png");
	playerGraphic->AddComponent(tankRenderer);
}
