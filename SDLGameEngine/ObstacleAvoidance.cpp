#include "ObstacleAvoidance.h"
#include "Game.h"
#include "Physics.h"
#include "RaycastHit.h"
#include "Collider.h"
#include "Rect.h"

ObstacleAvoidance::ObstacleAvoidance()
{
}


ObstacleAvoidance::~ObstacleAvoidance()
{
}

void ObstacleAvoidance::Start()
{
	if (target == nullptr)
	{
		target = Instantiate("target")->transform;
	}
}

void ObstacleAvoidance::Update()
{
	RaycastHit hit = game->physics->Raycast(gameObject->transform->GetAbsolutePosition(), -gameObject->transform->Up(), lookAhead, avoidLayer);
	if (hit.collider != nullptr)
	{
		Vector2 toVec = gameObject->transform->GetAbsolutePosition() - hit.point;
		float dist = toVec.Dot(hit.normal);
		target->SetAbsolutePosition(hit.point + hit.normal * dist);
		SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, hit.point.x - Camera::x, hit.point.y - Camera::y, target->GetAbsolutePosition().x - Camera::x, target->GetAbsolutePosition().y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(target->GetAbsolutePosition().x - Camera::x - 5, target->GetAbsolutePosition().y - Camera::y - 5, 10, 10));
		Seek::Update();
	}
	else
	{
		steering.linear = 0;
	}
}

