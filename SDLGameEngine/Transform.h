#pragma once
#include <SDL.h>
#include "Component.h"
#include "Vector2.h"

class Transform :
	public Component
{
public:
	Transform();
	Transform(GameObject* _gameObject, float x = 0, float y = 0, float _angle = 0, float xScale = 1, float yScale = 1);
	~Transform();

	Vector2 GetAbsolutePosition();
	float GetAbsoluteAngle();
	Vector2 GetAbsoluteScale();

	void SetParentRelative(Transform* _parent);

	Vector2 position;
	float angle;
	Vector2 scale;

	Vector2 Right();
	Vector2 Up();

	Transform* parent = NULL;
};

