#include "Input.h"



Input::Input()
{
}


Input::~Input()
{
}

void Input::Update()
{
	currentEvents.clear();
	//Event handler
	SDL_Event* e = new SDL_Event();
	while (SDL_PollEvent(e) != 0)
	{
		currentEvents.push_back(e);
	}
}                   

//bool Input::GetMouseButtonDown(SDL_MouseButtonEvent button)
//{
//	for (SDL_Event* e : currentEvents)
//	{
//		if (e->type == SDL_MOUSEBUTTONDOWN && e->button.type == button.type)
//		{
//
//		}
//	}
//	return true;
//}
