#include "PlayerControls.h"
#include "Input.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"


PlayerControls::PlayerControls()
{
}


PlayerControls::~PlayerControls()
{
}

void PlayerControls::Update()
{
	Vector2 direction;
	direction.x = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	direction.y = Input::GetKey(SDLK_s) ? 1 : Input::GetKey(SDLK_w) ? -1 : 0;
	direction.Normalize();
	gameObject->transform->SetAbsolutePositionDelta(direction * speed * Time::DeltaTime());
	float angle = atan2(direction.y, direction.x);
	if (direction.Length() >= 0.01f)
	{
		gameObject->transform->SetAbsoluteAngle(angle * 180.0f / M_PI);
	}
}
