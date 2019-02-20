#include "Collider.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "Game.h"

Collider::Collider()
{

}


Collider::~Collider()
{
	game->physics->colliders.remove(this);
}

void Collider::Awake()
{
	rigidbody = gameObject->GetComponent<Rigidbody>();
	if (rigidbody && !isTrigger && !rigidbody->ContainsCollider(this))
	{
		rigidbody->AddCollider(this);
	}
	game->physics->colliders.push_back(this);
}

void Collider::FixedUpdate()
{
	Component::FixedUpdate();
}

void Collider::SetTrigger(bool toggle)
{
	isTrigger = toggle;
	if (rigidbody && !isTrigger && !rigidbody->ContainsCollider(this))
	{
		rigidbody->AddCollider(this);
	}
	else if(rigidbody && isTrigger && rigidbody->ContainsCollider(this))
	{
		rigidbody->RemoveCollider(this);
	}
}
bool Collider::GetTrigger()
{
	return isTrigger;
}