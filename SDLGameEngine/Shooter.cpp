#include <time.h>
#include <stdlib.h>
#include "Shooter.h"
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
#include "SpriteRenderer.h"
#include "Scene1.h"
#include "PlayerControls.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

Shooter::Shooter()
{
}


Shooter::~Shooter()
{
}

void Shooter::Awake()
{
	Camera::x = 0;
	Camera::y = 0;
	Camera::width = 1280;
	Camera::height = 720;
	Time::timeScale = 1;
}

GameObject* Shooter::BulletPrefab()
{
	GameObject* go = new GameObject(this, "bullet");
	go->AddComponent(new SpriteRenderer("Assets/Cannon_Ball.png"));
	go->AddComponent(new Bullet());
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
	return go;
}

GameObject* Shooter::EnemyPrefab()
{
	GameObject* go = new GameObject(this, "enemies");
	go->AddComponent(new SpriteRenderer("Assets/Enemies/Enemy.png"));

	GameObject* tgt = CreateGameObject("Target", Camera::x + rand() % Camera::width, Camera::y + rand() % Camera::height);
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));

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
	updateTarget->target = &tgt->transform->GetAbsolutePosition();
	updateTarget->maxTime = 20;
	go->AddComponent(updateTarget);

	updateTarget->targetObject = tgt;

	go->transform->SetRelativeScale(Vector2(0.2f, 0.2f));
	
	go->AddComponent(new Rigidbody());

	BoxCollider* col = new BoxCollider();
	go->AddComponent(col);

	col->SetDimension(Vector2(50, 50));

	return go;
}

void Shooter::Setup()
{
	AddPrefab("Bullet", std::bind(&Shooter::BulletPrefab, this));
	AddPrefab("Enemy", std::bind(&Shooter::EnemyPrefab, this));

	SetScene(new Scene1());
}



