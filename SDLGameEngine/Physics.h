#pragma once
#include <Box2D/Box2D.h>
#include "Vector2.h"
#include "LayerdStorage.h"

class Rigidbody;
class Collider;
class Physics
{
public:
	Physics();
	~Physics();

	void Start();
	void FixedUpdate();
	//void Cleanup();

	const b2Vec2 GetPhysicsCoordinates(const Vector2& pos);
	const Vector2 GetWorldCoordinates(const b2Vec2& pos);

	b2World& GetPhysicsWorld();

	uint8_t numberOfLayers = 1;
	std::list<Rigidbody*> rigidbodies;
	std::list<Collider*> colliders;
	void SetGravity(const Vector2& _gravity);

	void Extrapolate(float dt);

private:
    float worldScale = 100;
	Vector2 gravity = Vector2(0, 1000);
	b2World world = b2World(b2Vec2(0, 0));

	uint32_t velocityIterations = 8;
	uint32_t positionIterations = 3;

};

