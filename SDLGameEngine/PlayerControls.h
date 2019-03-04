#pragma once
#include "Behaviour.h"
class PlayerControls :
	public Behaviour
{
public:
	PlayerControls();
	~PlayerControls();

	float speed = 100;
	void Update();
};

