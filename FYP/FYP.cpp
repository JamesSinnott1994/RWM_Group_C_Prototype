// FYP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Classes
#include "Renderer.h"
#include "Sprite.h"
#include "KeyBoardInput.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

// Window width and height
const int windowWidth = 800;
const int windowHeight = 600;

int _tmain(int argc, _TCHAR* argv[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//SDL
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Create Renderer for the Window
			if (!Renderer::GetInstance()->Init(window, windowWidth, windowHeight))
			{
				return 0;
			}

			bool quit = false;

			SDL_Event e;
			while (!quit)
			{
				// Update keyboard
				while (SDL_PollEvent(&e) != 0)
				{
					KeyBoardInput::GetInstance()->updateKeyboard(e);
					switch (e.type)
					{
						case SDL_QUIT:
							quit = true;
							break;
					}
				}

				// Escape button
				if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_ESCAPE))
				{
					quit = true;
				}
			}// End while
		}// End inner else
	}// End outer else

	return 0;
}

