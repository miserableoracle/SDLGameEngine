#include "DynamicSteeringDemo.h"
#include "SteeringAgent.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"
#include "Align.h"
#include "Pursue.h"
#include "UpdateVectorTarget.h"
#include "MoveInCircle.h"


DynamicSteeringDemo::DynamicSteeringDemo()
{
}


DynamicSteeringDemo::~DynamicSteeringDemo()
{
}

void DynamicSteeringDemo::Awake()
{
	Game::screenWidth = 1920;
	Game::screenHeight = 1080;
}

void DynamicSteeringDemo::Setup()
{
	GameObject* go = CreateGameObject("Tank", screenWidth / 2, screenHeight / 2, 0);
	go->AddComponent(new Renderer(go, "Assets/Tank.png"));
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;

	GameObject* tgt = CreateGameObject("Target", 1900, 1000);
	tgt->AddComponent(new Renderer(tgt, "Assets/Target.png"));
	tgt->transform->scale.x = 0.1f;
	tgt->transform->scale.y = 0.1f;
	tgt->AddComponent(new MoveInCircle(tgt));

	Seek* seek = new Seek(go);
	seek->target = tgt->transform;
	seek->maxAccelaraction = 50;
	//go->AddComponent(seek);

	Flee* flee = new Flee(go);
	flee->target = tgt->transform;;
	flee->maxAccelaraction = 10;
	//go->AddComponent(flee);

	Arrive* arrive = new Arrive(go);
	arrive->target = tgt->transform;;
	arrive->maxAccelaraction = 1;
	//go->AddComponent(arrive);

	Align* align = new Align(go);
	align->orientation = 1.5f;
	//go->AddComponent(align);

	Pursue* pursue = new Pursue(go);
	pursue->target = tgt->transform;
	pursue->maxAccelaraction = 5;
	go->AddComponent(pursue);

	SteeringAgent* agent = new SteeringAgent(go);
	//agent->steerings.push_back(seek);
	//agent->steerings.push_back(flee);
	//agent->steerings.push_back(arrive);
	//agent->steerings.push_back(align);
	agent->steerings.push_back(pursue);
	agent->maxSpeed = 200;
	agent->velocity.y = -100;
	go->AddComponent(agent);

	//seek->agent = agent;
	//flee->agent = agent;
	//arrive->agent = agent;
	//align->agent = agent;
	pursue->agent = agent;

	UpdateVectorTarget* updateTarget = new UpdateVectorTarget(go);
	updateTarget->target = &tgt->transform->position;
	updateTarget->maxTime = 20;
	go->AddComponent(updateTarget);

	
	updateTarget->targetObject = tgt;
}
