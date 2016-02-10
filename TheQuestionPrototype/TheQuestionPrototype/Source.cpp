#include <iostream>
using namespace std;

#include <SDL.h>
#undef main

#include "Renderer.h"
#include "KeyBoardInput.h"
#include "Minion.h"
#include "TowerManager.h"
#include "Base.h"
#include "StormWarning.h"
#include <list>
#include "MinionManager.h"
#include "playertwo.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL


int main()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	int x = 0, y = 0;

	

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

			MinionManager::GetInstance()->addMinion(300, 100, 1);
			MinionManager::GetInstance()->addMinion(300, 300, 1);
			MinionManager::GetInstance()->addMinion(300, 500, 1);	

			MinionManager::GetInstance()->addMinion(700, 100, 2);
			MinionManager::GetInstance()->addMinion(700, 300, 2);
			MinionManager::GetInstance()->addMinion(700, 500, 2);

			TowerManager::GetInstance()->addTower(1, 100, 100);

			TowerManager::GetInstance()->addTower(2, 400, 400);

			Base::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);

			playertwo::GetInstance()->Init();

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
				ftime = (current_time - old_time) / 1000.0f;// Seconds
				//cout << ftime << endl;

				
				//minion->Update(x, y, ftime);
				MinionManager::GetInstance()->Update(x, y, ftime);

				while (SDL_PollEvent(&e) != 0)
				{
					KeyBoardInput::GetInstance()->updateKeyboard(e);
					switch (e.type)
					{
					
					case SDL_QUIT:
						quit = true;
						break;

					}
					//If a mouse button was pressed
					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						//If the left mouse button was pressed
						if (e.button.button == SDL_BUTTON_LEFT)
						{
							if (e.button.x > Base::GetInstance()->getRect().x && e.button.x < Base::GetInstance()->getRect().w + Base::GetInstance()->getRect().x &&
								e.button.y > Base::GetInstance()->getRect().y && e.button.y < Base::GetInstance()->getRect().h + Base::GetInstance()->getRect().y) {
								Base::GetInstance()->createMinion();
							}
							SDL_Point mouse = { e.button.x, e.button.y};

							TowerManager::GetInstance()->mouseClicked(mouse);
							MinionManager::GetInstance()->SelectedMouse(e.button.x, e.button.y);
							x = e.button.x;
							y = e.button.y;
						}
					}

					// Check if player two mouse is over minion
					if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_TAB))
					{

						int t = 0;
						MinionManager::GetInstance()->SelectedKeyboard(playertwo::GetInstance()->getRect().x + (playertwo::GetInstance()->getRect().w / 2), playertwo::GetInstance()->getRect().y + (playertwo::GetInstance()->getRect().h / 2));
						//for each(Minion *minion in *MinionManager::GetInstance()->ReturnMinions())
						//{
						/*if (minion->getRect().x > playertwo::GetInstance()->getRect().x + playertwo::GetInstance()->getRect().w
						&& minion->getRect().x + minion->getRect().w < playertwo::GetInstance()->getRect().x
						&& minion->getRect().y > playertwo::GetInstance()->getRect().y + playertwo::GetInstance()->getRect().h
						&& minion->getRect().y + minion->getRect().h < playertwo::GetInstance()->getRect().y)
						{

						}*/
						//}
					}
				}
				//update 
				StormWarning::GetInstance()->Update(ftime);
				TowerManager::GetInstance()->Update(ftime);
				playertwo::GetInstance()->Update();

				//draw
				Renderer::GetInstance()->ClearRenderer();
				//minion->Draw();
				/*Call Draw on objects here*/

				MinionManager::GetInstance()->Draw();
				playertwo::GetInstance()->Draw();
				TowerManager::GetInstance()->Draw();

				Base::GetInstance()->Draw();

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