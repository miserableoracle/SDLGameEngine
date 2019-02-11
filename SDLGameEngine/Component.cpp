#include "Component.h"
#include <iostream>
#include "GameObject.h"
#include "Transform.h"


Component::Component()
{
	
}

Component::Component(GameObject* _gameObject)
{
	gameObject = _gameObject;
}


Component::~Component()
{

}

void Component::Awake()
{

}

void Component::Start()
{

}

void Component::Update()
{

}

void Component::Cleanup()
{

}

void Component::OnUpdate()
{
	if (gameObject != nullptr)
	{
		if (!started)
		{
			Start();
			started = true;
		}
		else
		{
			Update();
		}
	}	
}


