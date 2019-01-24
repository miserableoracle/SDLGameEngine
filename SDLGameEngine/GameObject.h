#pragma once
#include <list>
#include <iostream>

class Component;
class Transform;
class Game;
class GameObject
{
public:
	GameObject();
	GameObject(Game* _game, std::string name = "", float x = 0, float y = 0, float _angle = 0, float xScale = 1, float yScale = 1);
	~GameObject();
	void AddComponent(Component* component);
	template<class T> T* GetComponent();
	template<class T> void RemoveComponent();
	/*template<class T> T* GetComponents();
	template<class T> void RemoveComponents();*/
	void Start();
	void Update();
	void Cleanup();
	std::string name;
	Transform* transform;

private:
	std::list<Component*> components;
	Game* game;
};

template<class T> T* GameObject::GetComponent()
{
	for (Component* component : components)
	{
		try
		{
			T* found = (T*)component;
			return found;
		}
		catch (const std::exception&)
		{

		}
	}
	std::cout << "Component not found";
	return NULL;
}

template<class T> void GameObject::RemoveComponent()
{
	for (Component* component : components)
	{
		try
		{
			Component* found = (T*)component;
			components.remove(component);
			return;
		}
		catch (const std::exception&)
		{

		}
	}
	std::cout << "Component not found";
	return;
}


