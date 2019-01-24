#include "MoveInCircle.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2.h"
#include "Game.h"

MoveInCircle::MoveInCircle()
{
}


MoveInCircle::~MoveInCircle()
{
}

MoveInCircle::MoveInCircle(GameObject* go) : Behaviour(go)
{

}

void MoveInCircle::Update()
{
	angle += angularSpeed / 60.0f;
	gameObject->transform->position.x = Game::screenWidth / 2 + radius * cos(angle);
	gameObject->transform->position.y = Game::screenHeight / 2 + radius * sin(angle);
	gameObject->transform->angle = angle * 180.0f / M_PI + 180;
}