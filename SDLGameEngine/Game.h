#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameObject.h"
#include "Input.h"
#include "Transform.h"
#include "Renderer.h"
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

	static int screenWidth;
	static int screenHeight;

protected:

	//The window we'll be rendering to
	
	std::list<GameObject*> gameObjects;
	std::list<Module*> modules;
};

