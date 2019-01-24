#include "Transform.h"



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
