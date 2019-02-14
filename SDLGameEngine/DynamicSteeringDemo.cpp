#include "DynamicSteeringDemo.h"
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
#include "SpriteRenderer.h"


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
	GameObject* go = CreateGameObject("Tank", 300, 200, 0);
	go->AddComponent(new SpriteRenderer("Assets/Tank.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));


	GameObject* tgt = CreateGameObject("Target", 1900, 1000);
	tgt->AddComponent(new  SpriteRenderer("Assets/Target.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));
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

	PathFollowing* pathFollowing = new PathFollowing(go);
	pathFollowing->target = tgt->transform;;
	pathFollowing->maxAccelaraction = 1;
	//go->AddComponent(pathFollowing);
	pathFollowing->waypoints.push_back(Vector2(50, 50));
	pathFollowing->waypoints.push_back(Vector2(100, 700));
	pathFollowing->waypoints.push_back(Vector2(200, 100));
	pathFollowing->waypoints.push_back(Vector2(350, 500));
	pathFollowing->waypoints.push_back(Vector2(450, 150));
	pathFollowing->waypoints.push_back(Vector2(600, 600));
	pathFollowing->waypoints.push_back(Vector2(750, 50));
	pathFollowing->waypoints.push_back(Vector2(900, 550));
	pathFollowing->waypoints.push_back(Vector2(1000, 100));
	pathFollowing->waypoints.push_back(Vector2(1150, 500));

	SteeringAgent* agent = new SteeringAgent(go);
	//agent->steerings.push_back(seek);
	//agent->steerings.push_back(flee);
	//agent->steerings.push_back(arrive);
	//agent->steerings.push_back(align);
	agent->steerings.push_back(pursue);
	//agent->steerings.push_back(pathFollowing);
	agent->maxSpeed = 200;
	agent->velocity.y = -100;
	go->AddComponent(agent);

	//seek->agent = agent;
	//flee->agent = agent;
	//arrive->agent = agent;
	//align->agent = agent;
	pursue->agent = agent;
	//pathFollowing->agent = agent;

	UpdateVectorTarget* updateTarget = new UpdateVectorTarget(go);
	updateTarget->target = &tgt->transform->GetAbsolutePosition();
	updateTarget->maxTime = 20;
	go->AddComponent(updateTarget);
	
	updateTarget->targetObject = tgt;

	//Time::timeScale = 0.3F;

	/*Texture* TEXT = new Texture();
	TEXT->loadFromRenderedText("xyz", { 1, 0, 0 }, TTF_OpenFont("Assets/lazy.ttf", 28));*/
}
