#pragma once

//Forward Declare
class GameObject;

class Component
{
public:
	 Component();
	 Component(GameObject* _gameObject);
	virtual ~Component();
	virtual void Start();
	virtual void Update();
	virtual void Cleanup();

	GameObject* gameObject;
};

