#pragma once
#include "Component.h"
class Behaviour :
	public Component
{
public:
	Behaviour();
	Behaviour(GameObject* _gameObject);
	virtual void Start();
	virtual void Update();
	virtual ~Behaviour();
};

