#include "PlayerControls.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Input.h"
#include "Game.h"

PlayerControls::PlayerControls()
{
}


PlayerControls::~PlayerControls()
{
}

void PlayerControls::Update()
{
	int horizontal = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	gameObject->transform->position.x += horizontal * xSpeed * Time::DeltaTime();
	int vertical = Input::GetKey(SDLK_w) ? -1 : Input::GetKey(SDLK_s) ? 1 : 0;
	gameObject->transform->position.y += vertical * ySpeed * Time::DeltaTime();
	if (vertical != 0 || horizontal != 0)
	{
		gameObject->transform->angle = atan2(vertical, horizontal) * 180 / M_PI;
	}
	if (Input::GetKeyDown(SDLK_SPACE))
	{
		game->Instantiate(game->Prefab("Bullet"), gameObject->transform->position, gameObject->transform->GetAbsoluteAngle() - 90);
	}
}
