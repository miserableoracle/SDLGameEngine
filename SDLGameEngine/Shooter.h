#pragma once
#include "Game.h"
class Shooter :
	public Game
{
public:
	Shooter();
	~Shooter();

	void Awake();
	void Setup();

	//GameObject* BulletPrefab();
};

