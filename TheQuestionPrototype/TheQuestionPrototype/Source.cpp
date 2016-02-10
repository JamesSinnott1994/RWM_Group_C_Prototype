#include <iostream>
using namespace std;

#include <SDL.h>
#undef main

#include "Renderer.h"
#include "KeyBoardInput.h"
<<<<<<< HEAD
#include "Tower.h"
#include "Minion.h"
=======
#include "TowerManager.h"
#include "Base.h"
#include "StormWarning.h"
>>>>>>> origin/master
#include <list>
#include "MinionManager.h"

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
<<<<<<< HEAD
			list<Tower*> towers;
			//Minion *minion = new Minion(300, 300, 0);

			MinionManager::GetInstance()->addMinion(300, 300, 0);
			MinionManager::GetInstance()->addMinion(420, 420, 0);
			MinionManager::GetInstance()->addMinion(69, 69, 0);

			for (int i = 0; i < 10; i++)
			{
				towers.push_back(new Tower(i * 100, 100));
			}
=======
			

			TowerManager::GetInstance()->addTower(1, 100, 100);

			Base::GetInstance()->Init(SCREEN_WIDTH, SCREEN_HEIGHT);

>>>>>>> origin/master

			bool quit = false;
			SDL_Event e;

			// Timing variables
<<<<<<< HEAD
			Uint32 old_time, current_time = 0;
=======
			Uint32 old_time, current_time;
			current_time = SDL_GetTicks();
>>>>>>> origin/master
			float ftime;//time between frames

			while (!quit)
			{

				// Update the timing information
				old_time = current_time;
				current_time = SDL_GetTicks();
				ftime = (current_time - old_time) / 1000.0f;// Seconds
				//cout << ftime << endl;

<<<<<<< HEAD
				
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
					int tempX = 0, tempY = 0;
					SDL_GetMouseState(&tempX, & tempY);
					//cout << tempX << " , " << tempY << endl;
					MinionManager::GetInstance()->Selected(tempX,tempY);
				}
				
				//minion->Update(x, y, ftime);
				MinionManager::GetInstance()->Update(x, y, ftime);

				while (SDL_PollEvent(&e) != 0){
=======
				while (SDL_PollEvent(&e) != 0)
				{
>>>>>>> origin/master
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
						}
					}
				}
				//update 
				StormWarning::GetInstance()->Update(ftime);
				TowerManager::GetInstance()->Update(ftime);

				//draw
				Renderer::GetInstance()->ClearRenderer();
<<<<<<< HEAD
				//minion->Draw();
				/*Call Draw on objects here*/
				for each(Tower * t in towers)
				{
					t->Draw();
				}
				MinionManager::GetInstance()->Draw();
=======

				TowerManager::GetInstance()->Draw();

				Base::GetInstance()->Draw();

>>>>>>> origin/master
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