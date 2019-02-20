#pragma once
#include "Component.h"
#include <Box2D/Box2D.h>

class Rigidbody;
class Collider :
	public Component
{
public:
	Collider();
	virtual ~Collider();

	b2FixtureDef fixtureDef;
	b2Fixture* fixture;

	void Awake();
	void FixedUpdate();

	void SetTrigger(bool toggle);
	bool GetTrigger();
protected:
	bool isTrigger = false;
	Rigidbody* rigidbody = NULL;
};

