#pragma once
#include "Behaviour.h"
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

	float xSpeed = 500;
	float ySpeed = 500;

	virtual void Update();
};

