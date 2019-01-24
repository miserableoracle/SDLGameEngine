#include "Behaviour.h"



Behaviour::Behaviour()
{
}

Behaviour::Behaviour(GameObject* _gameObject) : Component(_gameObject)
{

}

void Behaviour::Start()
{

}

void Behaviour::Update()
{
	Component::Update();
}

Behaviour::~Behaviour()
{
}
