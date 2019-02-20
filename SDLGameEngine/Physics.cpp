#include "Physics.h"
#include "Rigidbody.h"
#include "Time.h"

Physics::Physics()
{
	/*rigidbodies = std::list<Rigidbody*>();
	colliders = std::list<Collider*>();*/
}


Physics::~Physics()
{
}

void Physics::Start()
{

}

void Physics::FixedUpdate()
{
	world.Step(Time::FixedDeltaTime(), velocityIterations, positionIterations);
}

void Physics::SetGravity(const Vector2& _gravity)
{
	gravity = _gravity;
	world.SetGravity(GetPhysicsCoordinates(gravity));
}


const b2Vec2 Physics::GetPhysicsCoordinates(const Vector2& pos)
{
	return b2Vec2(pos.x / worldScale, pos.y / worldScale);
}
const Vector2 Physics::GetWorldCoordinates(const b2Vec2& pos)
{
	return Vector2(pos.x * worldScale, pos.y * worldScale);
}

b2World& Physics::GetPhysicsWorld()
{
	return world;
}

void Physics::Extrapolate(float dt)
{
		for (auto rigidbody : rigidbodies)
		{
			if (rigidbody != NULL)
			{
				rigidbody->Extrapolate(dt);
			}
		}

}
