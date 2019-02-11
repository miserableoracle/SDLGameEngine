#include "Transform.h"
#include "Game.h"



Transform::Transform()
{
	position.x = 0;
	position.y = 0;
}


Transform::Transform(GameObject* _gameObject, float x, float y, float _angle, float xScale, float yScale) : Component(_gameObject)
{
	position.x = x;
	position.y = y;
	angle = _angle;
	scale.x = xScale;
	scale.y = yScale;
}

Transform::~Transform()
{
}

Vector2 Transform::GetAbsolutePosition()
{
	if (parent == NULL)
	{
		return position;
	}
	const float& parentAngle = parent->GetAbsoluteAngle() * M_PI / 180.0f;
	const Vector2& rel = Vector2(position.x * cos(parentAngle) - position.y * sin(parentAngle), position.x * sin(parentAngle) + position.y * cos(parentAngle));
	const Vector2& pos = parent->GetAbsolutePosition() + rel;
	SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(Game::gRenderer, parent->GetAbsolutePosition().x - Camera::x, parent->GetAbsolutePosition().y - Camera::y, pos.x - Camera::x, pos.y - Camera::y);
	return pos;
}

float Transform::GetAbsoluteAngle()
{
	if (parent == NULL)
	{
		return angle;
	}
	return parent->GetAbsoluteAngle() + angle;
}

Vector2 Transform::GetAbsoluteScale()
{
	if (parent == NULL)
	{
		return scale;
	}
	return parent->GetAbsoluteScale() * scale;
}

void Transform::SetParentRelative(Transform* _parent)
{
	Vector2 relativePos = GetAbsolutePosition() - _parent->GetAbsolutePosition();
	const float& parentAngle = -_parent->GetAbsoluteAngle();
	position =  Vector2(relativePos.x * cos(parentAngle) - relativePos.y * sin(parentAngle), relativePos.x * sin(parentAngle) + relativePos.y * cos(parentAngle));
	angle = GetAbsoluteAngle() - _parent->GetAbsoluteAngle();
	const Vector2& parentScale = _parent->GetAbsoluteScale();
	const Vector2& myScale = GetAbsoluteScale();
	scale.x = parentScale.x != 0 ? myScale.x / parentScale.x : 1;
	scale.y = parentScale.y != 0 ? myScale.y / parentScale.y : 1;
	parent = _parent;
}

Vector2 Transform::Right()
{
	const float& absoluteAngle = GetAbsoluteAngle() * M_PI / 180.0f;
	return Vector2(cos(absoluteAngle), sin(absoluteAngle));
}

Vector2 Transform::Up()
{
	const float& absoluteAngle = GetAbsoluteAngle() * M_PI / 180.0f;
	return Vector2(-sin(absoluteAngle), cos(absoluteAngle));
}