#include <time.h>
#include <stdlib.h>
#include "Shooter.h"
#include "PlayerControls.h"
#include "Bullet.h"
#include "GameObject.h"
#include "SteeringAgent.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"
#include "Align.h"
#include "Pursue.h"
#include "UpdateVectorTarget.h"
#include "MoveInCircle.h"
#include "Time.h"
#include "PathFollowing.h"
#include "Shoot.h"
#include "CameraFollow.h"

Shooter::Shooter()
{
}


Shooter::~Shooter()
{
}

void Shooter::Awake()
{
	Camera::x = -200;
	Camera::y = -200;
	Camera::width = 800;
	Camera::height = 600;
}

GameObject* Shooter::BulletPrefab()
{
	GameObject* go = new GameObject(this, "bullet");
	go->AddComponent(new Renderer(go, "Assets/Cannon_Ball.png"));
	go->AddComponent(new Bullet());
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;
	return go;
}

GameObject* Shooter::EnemyPrefab()
{
	GameObject* go = new GameObject(this, "enemies");
	go->AddComponent(new Renderer(go, "Assets/Enemies/Enemy.png"));

	GameObject* tgt = CreateGameObject("Target", Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height);
	tgt->transform->scale.x = 0.1f;
	tgt->transform->scale.y = 0.1f;

	Arrive* arrive = new Arrive(go);
	arrive->target = tgt->transform;;
	arrive->maxAccelaraction = 1;
	go->AddComponent(arrive);

	SteeringAgent* agent = new SteeringAgent(go);
	agent->steerings.push_back(arrive);
	agent->maxSpeed = 200;
	agent->velocity.y = -100;
	go->AddComponent(agent);
	arrive->agent = agent;

	UpdateVectorTarget* updateTarget = new UpdateVectorTarget(go);
	updateTarget->target = &tgt->transform->position;
	updateTarget->maxTime = 20;
	go->AddComponent(updateTarget);

	updateTarget->targetObject = tgt;
	
	go->transform->scale.x = 0.2f;
	go->transform->scale.y = 0.2f;
	return go;
}

void Shooter::Setup()
{
	AddPrefab("Bullet", std::bind(&Shooter::BulletPrefab, this));
	AddPrefab("Enemy", std::bind(&Shooter::EnemyPrefab, this));

	GameObject* bg = CreateGameObject("bg", 300, 200, 0);
	bg->AddComponent(new Renderer(bg, "Assets/bg.png"));

	GameObject* go = CreateGameObject("Tank", 300, 200, 0);
	go->AddComponent(new Renderer(go, "Assets/Target.png"));
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;
	GameObject* graphic = CreateGameObject("TankGraphic", 0, 0, 90);
	graphic->AddComponent(new Renderer(go, "Assets/Tank.png"));
	/*graphic->transform->scale.x = 0.1f;
	graphic->transform->scale.y = 0.1f;*/
	//graphic->transform->SetParentRelative(go->transform);
	graphic->transform->parent = go->transform;

	for (int i = 0; i < 10; i++)
	{
		GameObject* enemy = EnemyPrefab();
		enemy->transform->position.x = Camera::x + rand() % Camera::width;
		enemy->transform->position.y = Camera::y + rand() % Camera::height;
		gameObjects.push_back(enemy);
	}

	go->AddComponent(new PlayerControls());
	go->AddComponent(new CameraFollow());
	graphic->AddComponent(new Shoot());
}



