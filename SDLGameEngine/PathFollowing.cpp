#include "PathFollowing.h"
#include "Game.h"


PathFollowing::PathFollowing()
{
}

PathFollowing::PathFollowing(GameObject* go) : Arrive(go)
{

}


PathFollowing::~PathFollowing()
{
}

void PathFollowing::Start()
{
	currentWaypoint = waypoints.begin();

	float distance = (gameObject->transform->position - *currentWaypoint).Length();
	float currentDistance = 0;
	for (std::list<Vector2>::iterator it = waypoints.begin(); it != waypoints.end(); ++it)
	{
		currentDistance = (gameObject->transform->position - *it).Length();
		if (currentDistance < distance)
		{
			distance = currentDistance;
			currentWaypoint = it;
		}
	}

	target->position = *currentWaypoint;


	Vector2 closestWaypoint = *currentWaypoint;
	++currentWaypoint;
	if (currentWaypoint != waypoints.end())
	{
		Vector2 nextPoint = *currentWaypoint;
		Vector2 lineVector = nextPoint - closestWaypoint;
		Vector2 toVector = gameObject->transform->position - closestWaypoint;
		Vector2 projection = toVector.Dot(lineVector) * (lineVector / (lineVector.Length() * lineVector.Length()));
		target->position = projection + closestWaypoint;
		--currentWaypoint;
	}

	Arrive::Start();
}

void PathFollowing::Update()
{
	if ((target->position - gameObject->transform->position).Length() < distanceThreshold)
	{
		if (currentWaypoint != waypoints.end())
		{
			++currentWaypoint;
			if (currentWaypoint != waypoints.end())
			{
				target->position = *currentWaypoint;
			}
		}
	}

	// Debug Graphics
	Vector2 start = *waypoints.begin();
	SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	for (std::list<Vector2>::iterator it = waypoints.begin(); it != waypoints.end(); ++it)
	{
		SDL_RenderDrawLine(Game::gRenderer, start.x, start.y, (*it).x, (*it).y);
		start = *it;
	}

	Arrive::Update();
}
