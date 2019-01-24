#pragma once
#include <SDL.h>
#include "Module.h"
#include <list>
class Input:
	public Module
{
public:
	Input();
	~Input();
	//void Start();
	void Update();
	//bool GetMouseButtonDown(SDL_MouseButtonEvent button);
	//bool GetMouseButton(SDL_MouseButtonEvent button);
	//bool GetMouseButtonUp(SDL_MouseButtonEvent button);
	//bool GetKeyDown(SDL_Keycode key);
	//bool GetKey(SDL_Keycode key);
	//bool GetKeyUp(SDL_Keycode key);
private:
	Uint8* keyStates;
	std::list<SDL_Event*> currentEvents;
};

