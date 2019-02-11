#include "MoveInCircle.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2.h"
#include "Game.h"
#include "Time.h"

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
	angle += angularSpeed * Time::DeltaTime();
	gameObject->transform->position.x = Game::screenWidth / 2 + radius * cos(angle);
	gameObject->transform->position.y = Game::screenHeight / 2 + radius * sin(angle);
	gameObject->transform->angle = angle * 180.0f / M_PI + 180;
	//gameObject->GetComponent<Renderer>()->texture->loadFromRenderedText("xyz", { 1, 0, 0 }, TTF_OpenFont("Assets/lazy.ttf", 28));
	Behaviour::Update();
}