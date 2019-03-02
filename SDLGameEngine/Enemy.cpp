#include "Enemy.h"
#include "Input.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "Physics.h"
#include "RaycastHit.h"
#include "Game.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


void Enemy::Update()
{
	Behaviour::Update();
	if (Input::GetKeyDown(SDLK_SPACE))
	{
		//gameObject->GetComponent<Rigidbody>()->SetBodyType(Rigidbody::kinematicBody);
	}
	//RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), -gameObject->transform->Up(), 10000);
}