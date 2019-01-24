#include "KinematicDemo.h"
#include "KinematicAgent.h"
#include "KinematicSeek.h"
#include "UpdateTarget.h"

KinematicDemo::KinematicDemo()
{
}


KinematicDemo::~KinematicDemo()
{
}

void KinematicDemo::Setup()
{
	GameObject* go = CreateGameObject("Tank", 1920 / 2, 1080 / 2, 45);
	go->AddComponent(new Renderer(go, "Assets/Tank.png"));
	go->transform->scale.x = 0.1f;
	go->transform->scale.y = 0.1f;

	KinematicSeek* steer = new KinematicSeek(go);
	steer->target.x = 1920 / 2 + 1;
	steer->target.y = 1080 / 2 + 1;
	steer->maxSpeed = 500;
	go->AddComponent(steer);

	KinematicAgent* agent = new KinematicAgent(go);
	agent->steering = steer;
	go->AddComponent(agent);

	UpdateTarget* updateTarget = new UpdateTarget(go);
	updateTarget->steer = steer;
	go->AddComponent(updateTarget);

	GameObject* tgt = CreateGameObject("Target", steer->target.x, steer->target.y);
	tgt->AddComponent(new Renderer(tgt, "Assets/Target.png"));
	tgt->transform->scale.x = 0.1f;
	tgt->transform->scale.y = 0.1f;
	updateTarget->targetObject = tgt;
}
