#pragma once
#include "Component.h"
#include "Physics.h"

class Collider;
class Rigidbody
	: public Component
{
public:
	Rigidbody();
	Rigidbody(int _layer);
	virtual ~Rigidbody();

	void Awake();
	//void Start();
	void FixedUpdate();

	enum bodyType
	{
		staticBody,
		kinematicBody,
		dynamicBody
	};

	void SetBodyType(const bodyType& _type);
	const bodyType& GetBodyType() const;

	b2Body* body;

	void Extrapolate(float dt);

	void SetLayer(int _layer);
	int GetLayer();

	void AddForce(Vector2 force);
	void AddForce(Vector2 force, Vector2 point);

	void SetMass(float mass);
	float GetMass();

	bool ContainsCollider(Collider* col);
	void AddCollider(Collider* col);
	void RemoveCollider(Collider* col);
private:
	bodyType type;
	Physics* physics;
	int layer;
	/*b2Transform physicsTransform;*/
	std::list<Collider*> myColliders;
};

