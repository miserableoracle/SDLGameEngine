#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Scene.h"


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
	if (scene != NULL)
	{
		scene->ReleaseFromScene(this);
	}
	for (Component* component : components)
	{
		delete component;
		component = NULL;
	}

}

void GameObject::AddComponent(Component* component)
{
	component->gameObject = this;
	component->game = game;
	component->scene = scene;
	components.push_back(component);
	if (awoken)
	{
		component->Awake();
	}
}

void GameObject::Awake()
{
	awoken = true;
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

void GameObject::FixedUpdate()
{
	for (Component* component : components)
	{
		if (component->enabled)
		{
			component->FixedUpdate();
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

