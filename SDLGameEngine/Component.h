#pragma once
#include "Vector2.h"
//Forward Declare
class GameObject;
class Game;

class Component
{
	friend class GameObject;
public:
	 Component();
	 Component(GameObject* _gameObject);
	virtual ~Component();
	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void Cleanup();

	GameObject* gameObject;
	bool enabled = true;

	Game* game;

private:
	bool started = false;
	void OnUpdate();
};

