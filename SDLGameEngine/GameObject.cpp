#include "GameObject.h"
#include "Component.h"
#include "Transform.h"


GameObject::GameObject()
{
	transform = new Transform(0, 0);
	AddComponent((Component*)transform);
}

GameObject::GameObject(const GameObject &gameObject)
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
	for (Component* component : components)
	{
		delete component;
	}

}

void GameObject::AddComponent(Component* component)
{
	component->gameObject = this;
	component->game = game;
	components.push_back(component);
}

void GameObject::Start()
{
	for (Component* component : components)
	{
		component->Awake();
	}
}

void GameObject::Update()
{
	for (Component* component : components)
	{
		if (component->enabled)
		{
			component->OnUpdate();
		}
	}
}

void GameObject::Cleanup()
{
	for (Component* component : components)
	{
		component->Cleanup();
	}
}

