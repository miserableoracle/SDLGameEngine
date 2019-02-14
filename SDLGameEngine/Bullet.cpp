#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Game.h"

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Behaviour::Update();
	Vector2 up = gameObject->transform->Up();
	gameObject->transform->SetAbsolutePositionDelta(speed * up * Time::DeltaTime());
	timer += Time::DeltaTime();
	if (timer > destroyTime)
	{
		game->Destroy(gameObject);
	}
}
