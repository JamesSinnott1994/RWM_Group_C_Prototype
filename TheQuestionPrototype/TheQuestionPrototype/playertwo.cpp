#include "playertwo.h"

bool playertwo::instanceFlag = false;
playertwo* playertwo::instance = NULL;

playertwo* playertwo::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new playertwo;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void playertwo::Init()
{
	x = 50;
	y = 50;
	w = 50;
	h = 50;
}

void playertwo::Update()
{
	// Move mouse
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_UP))
	{
		y -= 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_DOWN))
	{
		y += 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT))
	{
		x -= 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT))
	{
		x += 0.05f;
	}

	// Select minion
	/*if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_TAB))
	{

	}*/
}

void playertwo::Draw()
{
	SDL_Rect outerRect = { x, y, w, h };
	SDL_SetRenderDrawColor(Renderer::GetInstance()->Get_SDL_RENDERER(), 187, 122, 87, 255);// Brown
	SDL_RenderFillRect(Renderer::GetInstance()->Get_SDL_RENDERER(), &outerRect);
}

SDL_Rect playertwo::getRect()
{
	SDL_Rect rect = { x, y, w, h };

	return rect;
}