#include "Rigidbody.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Collider.h"
#include <algorithm>

Rigidbody::Rigidbody()
{
	
}

Rigidbody::Rigidbody(int _layer)
{
	layer = _layer;
}

Rigidbody::~Rigidbody()
{
	physics->rigidbodies.remove(this);
}

void Rigidbody::Awake()
{
	Component::Awake();
	physics = game->physics;
	physics->rigidbodies.push_back(this);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	if (gameObject != NULL)
	{
		b2Vec2 pos = physics->GetPhysicsCoordinates(gameObject->transform->GetAbsolutePosition());
		bodyDef.position.Set(pos.x, pos.y);
		bodyDef.angle = gameObject->transform->GetAbsoluteAngle() * M_PI / 180.0f;
	}
	else
	{
		bodyDef.position.Set(0, 0);
	}

	body = physics->GetPhysicsWorld().CreateBody(&bodyDef);

	std::list<Collider*> allColliders = gameObject->GetComponents<Collider>();

	for (Collider* col : allColliders)
	{
		if (!col->GetTrigger())
		{
			col->fixture = body->CreateFixture(&col->fixtureDef);
			col->fixture->SetRestitution(1);
			col->fixture->SetFriction(0);
			myColliders.push_back(col);
		}
	}
}

void Rigidbody::SetBodyType(const bodyType& _type)
{
	type = _type;
	switch (type)
	{
	case staticBody:
		body->SetType(b2_staticBody);
		break;
	case kinematicBody:
		body->SetType(b2_kinematicBody);
		break; 
	case dynamicBody:
		body->SetType(b2_dynamicBody);
		break;
	default:
		break;
	}
}

const Rigidbody::bodyType& Rigidbody::GetBodyType() const
{
	return type;
}

void Rigidbody::FixedUpdate()
{
	Component::FixedUpdate();
	gameObject->transform->SetAbsolutePosition(physics->GetWorldCoordinates(body->GetPosition()));
	gameObject->transform->SetAbsoluteAngle(body->GetAngle() * 180.0f / M_PI);
}

void Rigidbody::Extrapolate(float dt)
{
	b2Vec2 delta = body->GetLinearVelocity();
	delta *= dt;
	b2Vec2 extrapolatedPos = body->GetPosition() + delta;
	gameObject->transform->SetAbsolutePosition(physics->GetWorldCoordinates(extrapolatedPos));
	gameObject->transform->SetAbsoluteAngle((body->GetAngle() + body->GetAngularVelocity() * dt) * 180.0f / M_PI);
}

void Rigidbody::SetLayer(int _layer)
{
	if (layer != _layer)
	{
		physics->rigidbodies.remove(this);
		layer = _layer;
		physics->rigidbodies.push_back(this);
	}
}

int Rigidbody::GetLayer()
{
	return layer;
}

void Rigidbody::AddForce(Vector2 force)
{
	body->ApplyForceToCenter(physics->GetPhysicsCoordinates(force), true);
}

void Rigidbody::AddForce(Vector2 force, Vector2 center)
{
	body->ApplyForce(physics->GetPhysicsCoordinates(force), physics->GetPhysicsCoordinates(center), true);
}

void Rigidbody::SetMass(float mass)
{
	b2MassData* massData = NULL;
	body->GetMassData(massData);
	if (massData != NULL)
	{
		massData->mass = mass;
		body->SetMassData(massData);
	}
}

float Rigidbody::GetMass()
{
	return body->GetMass();
}

bool Rigidbody::ContainsCollider(Collider* col)
{
	return std::find(myColliders.begin(), myColliders.end(), col) != myColliders.end();
}

void Rigidbody::AddCollider(Collider* col)
{
	col->fixture = body->CreateFixture(&col->fixtureDef);
	col->fixture->SetRestitution(1);
	col->fixture->SetFriction(0);
	myColliders.push_back(col);
}

void Rigidbody::RemoveCollider(Collider* col)
{
	if (col->fixture)
	{
		body->DestroyFixture(col->fixture);
	}
	col->fixture = NULL;
	myColliders.remove(col);
}

