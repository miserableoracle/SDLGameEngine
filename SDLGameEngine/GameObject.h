#pragma once
#include <list>
#include <iostream>

class Component;
class Transform;
class Game;
class Scene;
class GameObject
{
public:
	GameObject();
	GameObject(Game* _game, std::string name = "", float x = 0, float y = 0, float _angle = 0, float xScale = 1, float yScale = 1);
	GameObject(const GameObject &gameObject);
	~GameObject();
	void AddComponent(Component* component);
	template<class T> T* GetComponent();
	template<class T> void RemoveComponent();
	/*template<class T> T* GetComponents();
	template<class T> void RemoveComponents();*/
	void Awake();
	void Update();
	void Cleanup();
	std::string name;
	Transform* transform;
	inline void SetActive(bool toggle) { active = toggle; }
	inline bool isActive() { return active; }
	inline const Scene* const GetScene() { return scene; }
	inline const Game* const GetGame() { return game; }

private:
	std::list<Component*> components;
	Game* game = NULL;
	Scene* scene = NULL;
	bool active = true;
	friend class Scene;
};

template<class T> T* GameObject::GetComponent()
{
	for (Component* component : components)
	{
		T* found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			return found;
		}
	}
	std::cout << "Component not found";
	return NULL;
}

template<class T> void GameObject::RemoveComponent()
{
	for (Component* component : components)
	{
		Component* found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			components.remove(component);
			return;
		}		
	}
	std::cout << "Component not found";
	return;
}


