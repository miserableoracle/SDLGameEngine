#pragma once
#include "Behaviour.h"
class Bullet :
	public Behaviour
{
public:
	Bullet();
	~Bullet();

	float speed = 1000;
	float destroyTime = 1;
	void Update();
private:
	float timer = 0;
};

