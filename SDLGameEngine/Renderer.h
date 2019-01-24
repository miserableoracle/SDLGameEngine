#pragma once
#include "Component.h"
#include "Texture.h"
#include "Vector2.h"

class Renderer:
	public Component
{
public:
	Renderer();
	Renderer(GameObject* _gameObject, std::string _filePath, SDL_Rect* _clip = NULL);
	virtual ~Renderer();
	void Start();
	void Update();

	std::string filePath;
	Texture* texture = NULL;
	SDL_Rect* clip = NULL;
	Vector2* center;
};

