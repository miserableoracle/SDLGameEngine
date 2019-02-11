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
	delete texture;
	delete clip;
	delete center;
}

void Renderer::Awake()
{
	texture = new Texture();
	texture->globalRenderer = Game::gRenderer;
	texture->loadFromFile(filePath);

	center = new Vector2(texture->getWidth() * gameObject->transform->GetAbsoluteScale().x / 2, texture->getHeight() * gameObject->transform->GetAbsoluteScale().y / 2);
}

void Renderer::Update()
{
	SDL_Point* pivot = new SDL_Point();
	pivot->x = floor(center->x);
	pivot->y = floor(center->y);
	int xPos = ceil(gameObject->transform->GetAbsolutePosition().x - texture->getWidth() * gameObject->transform->GetAbsoluteScale().x / 2);
	int yPos = ceil(gameObject->transform->GetAbsolutePosition().y - texture->getHeight() * gameObject->transform->GetAbsoluteScale().y / 2);
	xPos -= Camera::x;
	yPos -= Camera::y;
	SDL_Rect* renderQuad = new SDL_Rect();
	renderQuad->x = ceil(xPos);
	renderQuad->y = ceil(yPos);
	renderQuad->w = ceil(texture->getWidth() * gameObject->transform->GetAbsoluteScale().x);
	renderQuad->h = ceil(texture->getHeight() * gameObject->transform->GetAbsoluteScale().y);
	texture->render(xPos, yPos, clip, renderQuad, gameObject->transform->GetAbsoluteAngle(), pivot);
}