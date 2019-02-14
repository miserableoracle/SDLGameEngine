#pragma once
#include "Vector2.h"
#include <iostream>
//Forward Declare
class GameObject;
class Game;
class Scene;
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

	GameObject * Instantiate();

	GameObject* gameObject;
	bool enabled = true;

	Game* game;
	Scene* scene;

	GameObject* Instantiate(std::string name = "", const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(std::string name = "", const Vector2& position = Vector2(0, 0), const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const Vector2& position = Vector2(0, 0), const float& angle = 0);

private:
	bool started = false;
	void OnUpdate();
};

