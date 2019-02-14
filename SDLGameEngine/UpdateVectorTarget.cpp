#include "UpdateVectorTarget.h"
#include <stdlib.h>
#include <time.h>
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Camera.h"


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
	if ((gameObject->transform->GetAbsolutePosition() - target).Length() <= 10 || timer > maxTime)
	{
		target.x = Camera::x + rand() % Camera::width;
		target.y = Camera::y + rand() % Camera::height;
		targetObject->transform->SetAbsolutePosition(target);
		timer = 0;
	}
	Behaviour::Update();
}
