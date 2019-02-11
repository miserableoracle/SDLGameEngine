#pragma once
#include "Behaviour.h"
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

	float xSpeed = 200;
	float ySpeed = 200;

	virtual void Update();
};

