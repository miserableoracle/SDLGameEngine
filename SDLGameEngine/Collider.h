#pragma once
#include "Component.h"
#include <Box2D/Box2D.h>

class Collider :
	public Component
{
public:
	Collider();
	~Collider();
	b2BodyDef body;

};

