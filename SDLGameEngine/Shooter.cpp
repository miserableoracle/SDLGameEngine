#include "Shooter.h"
#include "PlayerControls.h"
#include "Bullet.h"
#include "GameObject.h"

Shooter::Shooter()
{
}


Shooter::~Shooter()
{
}

void Shooter::Awake()
{
	Camera::x = -200;
	Camera::width = 800;
	Camera::height = 600;
}

GameObject* BulletPrefab(Game* game)
{
	GameObject* go = new GameObject(game, "bullet");
	go->AddComponent(new Renderer(go, "Assets/Cannon_Ball.png"));
	go->AddComponent(new Bullet());
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;
	return go;
}

void Shooter::Setup()
{
	prefabs.insert(std::pair<std::string, prefab>("Bullet", &BulletPrefab));

	GameObject* go = CreateGameObject("Tank", 300, 200, 0);
	//go->AddComponent(new Renderer(go, "Assets/Target.png"));
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;
	GameObject* graphic = CreateGameObject("TankGraphic", 0, 0, 90);
	graphic->AddComponent(new Renderer(go, "Assets/Tank.png"));
	/*graphic->transform->scale.x = 0.1f;
	graphic->transform->scale.y = 0.1f;*/
	//graphic->transform->SetParentRelative(go->transform);
	graphic->transform->parent = go->transform;

	go->AddComponent(new PlayerControls());
}



