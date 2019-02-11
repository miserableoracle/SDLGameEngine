#pragma once
#include "Module.h"
#include <chrono>
class Time :
	public Module
{
public:
	Time();
	~Time();
	virtual void Start();
	virtual void Update();
	virtual void CleanUp();
	static float const& TimeElapsed();
	static float const& DeltaTime();
	static float const& UnscaledTimeElapsed();
	static float const& UnscaledDeltaTime();

	static float timeScale;

private:
	static float timeElapsedMs;
	static float deltaTimeMs;
	static std::chrono::high_resolution_clock::time_point unscaledTimeElapsedMs;
	static std::chrono::duration<double> unscaledDeltaTimeMs;
};

