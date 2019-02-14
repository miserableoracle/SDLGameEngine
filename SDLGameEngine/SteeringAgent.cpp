#include "SteeringAgent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Time.h"


SteeringAgent::SteeringAgent()
{
}

SteeringAgent::SteeringAgent(GameObject* go) : Behaviour(go)
{
}

SteeringAgent::~SteeringAgent()
{
}


void SteeringAgent::Update()
{
	for (SteeringBehaviour* steering : steerings)
	{
		velocity += steering->steering.weight * steering->steering.linear;
		angularSpeed += steering->steering.weight * steering->steering.angular;
	}
	if (velocity.Length() > maxSpeed)
	{
		velocity.Normalize();
		velocity *= maxSpeed;
	}

	gameObject->transform->SetAbsolutePositionDelta(velocity * Time::DeltaTime());
	//gameObject->transform->angle += (angularSpeed / 60.0f) * 180.0f / M_PI;
	gameObject->transform->SetAbsoluteAngle(atan2(velocity.y, velocity.x) * 180.0f / M_PI + 90.0f);

	/*SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(Game::gRenderer, gameObject->transform->position.x, gameObject->transform->position.y, gameObject->transform->position.x + velocity.x, gameObject->transform->position.y + velocity.y);*/
	Behaviour::Update();
}
