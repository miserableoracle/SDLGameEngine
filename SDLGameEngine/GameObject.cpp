#include "GameObject.h"
#include "Component.h"
#include "Transform.h"


GameObject::GameObject()
{
	transform = new Transform(0, 0);
	AddComponent((Component*)transform);
}

GameObject::GameObject(Game* _game, std::string _name, float x, float y, float angle, float xScale, float yScale)
{
	name = _name;
	transform = new Transform(this, x, y, angle, xScale, yScale);
	AddComponent((Component*)transform);
	game = _game;
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(Component* component)
{
	components.push_back(component);
}

void GameObject::Start()
{
	for (Component* component : components)
	{
		component->Start();
	}
}

void GameObject::Update()
{
	for (Component* component : components)
	{
		component->Update();
	}
}

void GameObject::Cleanup()
{
	for (Component* component : components)
	{
		component->Cleanup();
	}
}

