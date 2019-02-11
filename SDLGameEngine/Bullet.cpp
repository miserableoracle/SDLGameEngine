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
	gameObject->transform->position += speed * gameObject->transform->Up() * Time::DeltaTime();
	timer += Time::DeltaTime();
	if (timer > destroyTime)
	{
		game->Destroy(gameObject);
	}
}
