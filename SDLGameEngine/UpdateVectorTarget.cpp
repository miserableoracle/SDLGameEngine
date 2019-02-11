#include "UpdateVectorTarget.h"
#include <stdlib.h>
#include <time.h>
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"


UpdateVectorTarget::UpdateVectorTarget()
{
}

UpdateVectorTarget::UpdateVectorTarget(GameObject* go) : Behaviour(go)
{
}

UpdateVectorTarget::~UpdateVectorTarget()
{
}

void UpdateVectorTarget::Update()
{
	timer += Time::DeltaTime();
	if ((gameObject->transform->position - *target).Length() <= 10 || timer > maxTime)
	{
		target->x = rand() % 1280;
		target->y = rand() % 720;
		targetObject->transform->position = *target;
		timer = 0;
	}
	Behaviour::Update();
}
