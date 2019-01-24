#include "Renderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"

Renderer::Renderer()
{
	
}

Renderer::Renderer(GameObject* _gameObject, std::string _filePath, SDL_Rect* _renderQuad): Component(_gameObject)
{
	filePath = _filePath;
	clip = _renderQuad;
}

Renderer::~Renderer()
{
}

void Renderer::Start()
{
	texture = new Texture();
	texture->globalRenderer = Game::gRenderer;
	texture->loadFromFile(filePath);

	center = new Vector2(texture->getWidth() * gameObject->transform->scale.x / 2, texture->getHeight() * gameObject->transform->scale.y / 2);
}

void Renderer::Update()
{
	SDL_Point* pivot = new SDL_Point();
	pivot->x = ceil(center->x);
	pivot->y = ceil(center->y);
	int xPos = ceil(gameObject->transform->position.x - texture->getWidth() * gameObject->transform->scale.x / 2);
	int yPos = ceil(gameObject->transform->position.y - texture->getHeight() * gameObject->transform->scale.y / 2);
	SDL_Rect* renderQuad = new SDL_Rect();
	renderQuad->x = floor(xPos);
	renderQuad->y = floor(yPos);
	renderQuad->w = ceil(texture->getWidth() * gameObject->transform->scale.x);
	renderQuad->h = ceil(texture->getHeight() * gameObject->transform->scale.y);
	texture->render(xPos, yPos, clip, renderQuad, gameObject->transform->angle, pivot);
}