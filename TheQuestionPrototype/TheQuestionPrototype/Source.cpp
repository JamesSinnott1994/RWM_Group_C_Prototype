#include <iostream>
using namespace std;

#include <SDL.h>
#undef main

#include "Renderer.h"
#include "KeyBoardInput.h"
#include "TowerManager.h"
#include <list>

//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL


int main()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//SDL
#pragma region SDL STUFF
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create Renderer for the Window
			if (!Renderer::GetInstance()->Init(window, SCREEN_WIDTH, SCREEN_HEIGHT))
			{
				return 0;
			}
			

			TowerManager::GetInstance()->addTower(1, 100, 100);


			bool quit = false;
			SDL_Event e;

			// Timing variables
			Uint32 old_time, current_time;
			current_time = SDL_GetTicks();
			float ftime;//time between frames

			while (!quit)
			{
				// Update the timing information
				old_time = current_time;
				current_time = SDL_GetTicks();
				ftime = (current_time - old_time) / 1000.0f;
				//cout << ftime << endl;

				while (SDL_PollEvent(&e) != 0){
					KeyBoardInput::GetInstance()->updateKeyboard(e);
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;

					}
				}
				//update 

				//draw
				Renderer::GetInstance()->ClearRenderer();

				TowerManager::GetInstance()->Draw();

				Renderer::GetInstance()->RenderScreen();

				// Escape button
				if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_ESCAPE))
				{
					quit = true;
				}

			}//end while wuit
		}//end else
	}//end else

	return 0;
}