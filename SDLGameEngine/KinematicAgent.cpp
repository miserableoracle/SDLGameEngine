#include "KinematicAgent.h"
#include "GameObject.h"
#include "Transform.h"

KinematicAgent::KinematicAgent()
{
}

KinematicAgent::KinematicAgent(GameObject* go) : Behaviour(go)
{
}

KinematicAgent::~KinematicAgent()
{
}

void KinematicAgent::Update()
{
	gameObject->transform->position += steering->velocity / 60.0f;
	gameObject->transform->angle = atan2(steering->velocity.y, steering->velocity.x) * 180.0f / M_PI + 90.0f;
}
