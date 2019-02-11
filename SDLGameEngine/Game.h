#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <functional>
#include <map>
#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
#include "Renderer.h"
#include "Camera.h"

typedef GameObject* (*prefab)(Game* game);

class Game
{
public:
	Game();
	~Game();

	virtual void Awake();
	virtual bool Init();
	virtual void Setup();
	void Start();
	void Update();
	void End();
	static SDL_Window* gWindow;
	//The window renderer
	static SDL_Renderer* gRenderer;

	GameObject* CreateGameObject(std::string name = "", float x = 0, float y = 0, float angle = 0);
	GameObject* Instantiate(std::string name = "", const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const float& x = 0, const float& y = 0, const float& angle = 0);
	GameObject* Instantiate(std::string name = "", const Vector2& position = Vector2(0, 0), const float& angle = 0);
	GameObject* Instantiate(GameObject* go, const Vector2& position = Vector2(0, 0), const float& angle = 0);

	void Destroy(GameObject* go);

	static int screenWidth;
	static int screenHeight;

	std::map<std::string, std::function<GameObject*()>> prefabs;

	void AddPrefab(std::string name, std::function<GameObject*()> prefabRecipe);
	GameObject* Prefab(std::string name);

	static bool quit;

protected:

	//The window we'll be rendering to
	
	std::list<GameObject*> gameObjects;
	std::list<Module*> modules;

	std::list<GameObject*> objectsToDestroy;
};

