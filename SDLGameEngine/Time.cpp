#include "Time.h"
#include "SDL.h"
#include <iostream>

float Time::timeElapsedMs = 0;
float Time::deltaTimeMs = 0;
std::chrono::high_resolution_clock::time_point Time::unscaledTimeElapsedMs = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> Time::unscaledDeltaTimeMs = std::chrono::high_resolution_clock::now() - std::chrono::high_resolution_clock::now();
float Time::timeScale = 1;

Time::Time()
{
}

Time::~Time()
{
}

void Time::Start()
{
	timeElapsedMs = 0;
	unscaledTimeElapsedMs = std::chrono::high_resolution_clock::now();
	Module::Start();
}

void Time::Update()
{
	
	unscaledDeltaTimeMs = std::chrono::high_resolution_clock::now() - unscaledTimeElapsedMs;
	unscaledTimeElapsedMs = std::chrono::high_resolution_clock::now();
	if (unscaledDeltaTimeMs.count() < 0.033f)
	{
		deltaTimeMs = unscaledDeltaTimeMs.count() * (double)timeScale;
	}
	
	timeElapsedMs += deltaTimeMs;
	Module::Update();
	if (unscaledDeltaTimeMs.count() > 0.04167f)
	{
		std::cout << "unscaled time = " << unscaledDeltaTimeMs.count() << std::endl;
	}
}

float const& Time::TimeElapsed()
{
	return timeElapsedMs / 1000;
}

float const& Time::DeltaTime()
{
	return deltaTimeMs;
}

float const& Time::UnscaledTimeElapsed()
{
	return deltaTimeMs;
}

float const& Time::UnscaledDeltaTime()
{
	return unscaledDeltaTimeMs.count();
}

void Time::CleanUp()
{
	Module::CleanUp();
}
