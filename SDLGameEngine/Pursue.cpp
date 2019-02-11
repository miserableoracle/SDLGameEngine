#include "Pursue.h"
#include "SteeringAgent.h"
#include "Time.h"


Pursue::Pursue()
{
}

Pursue::Pursue(GameObject* go) : SteeringBehaviour(go)
{
}

Pursue::~Pursue()
{
}

void Pursue::Start()
{
	lastTragetPosition = target->position;
}

void Pursue::Update()
{

	Vector2 direction = target->position - gameObject->transform->position;
	float distance = direction.Length();

	float speed = agent->velocity.Length();

	float prediction;
	if (speed < distance / maxPrediction)
	{
		prediction = maxPrediction;
	}
	else
	{
		prediction = distance / speed;
	}

	Vector2 targetVel = (target->position - lastTragetPosition) * Time::DeltaTime();
	// Get direction to target
	steering.linear = target->position + targetVel * prediction - gameObject->transform->position;

	// Give full accelaration in this direction
	steering.linear.Normalize();
	steering.linear *= maxAccelaraction;

	// Output steering
	steering.angular = 0;
	lastTragetPosition = target->position;	
	SteeringBehaviour::Update();

}