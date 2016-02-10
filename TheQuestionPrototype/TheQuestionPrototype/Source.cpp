#include <iostream>
using namespace std;

#include <SDL.h>
#undef main

#include "Renderer.h"
#include "KeyBoardInput.h"
#include "Minion.h"
#include "TowerManager.h"
#include "StormWarning.h"
#include <list>
#include "MinionManager.h"
#include "playertwo.h"
#include "BaseManager.h"
#include "GoldManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1248;			//SDL
const int SCREEN_HEIGHT = 704;			//SDL


int main()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	int x = 0, y = 0;

	int newMinionX = 400;
	int newMinionX2 = 400;
	int newMinionY2 = 480;

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

			TowerManager::GetInstance()->addTower(1, 474, 100);
			TowerManager::GetInstance()->addTower(1, 774, 100);

			TowerManager::GetInstance()->addTower(2, 474, 400);
			TowerManager::GetInstance()->addTower(2, 774, 400);
			BaseManager::GetInstance()->Init();

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
							if (e.button.x > BaseManager::GetInstance()->getRect1().x && e.button.x < BaseManager::GetInstance()->getRect1().w + BaseManager::GetInstance()->getRect1().x &&
								e.button.y > BaseManager::GetInstance()->getRect1().y && e.button.y < BaseManager::GetInstance()->getRect1().h + BaseManager::GetInstance()->getRect1().y) {

								if (GoldManager::GetInstance()->getGold(1) >= 20)
								{
									cout << "CREATE MINIONS!!!!" << endl;
									newMinionX += 100;
									MinionManager::GetInstance()->addMinion(newMinionX, 100, 1);
									if (newMinionX >= 700)
										newMinionX = 400;

									GoldManager::GetInstance()->subtractGold(20, 1);
								}
							}
							// Base clicked

							SDL_Point mouse = { e.button.x, e.button.y};

							MinionManager::GetInstance()->SelectedMouse(e.button.x, e.button.y);
							x = e.button.x;
							y = e.button.y;

							if (TowerManager::GetInstance()->mouseClicked(mouse))
							{
								TowerManager::GetInstance()->TeamsOneMinions -= 1;

								for each(Minion * minion in *MinionManager::GetInstance()->ReturnMinionsTeam1())
								{
									if (minion->InTower)
									{
										SDL_Rect temp = minion->getRect();
										temp.x += 300;
										minion->setRect(temp);
										minion->InTower = false;
										break;
									}
								}
							}
						}
					}

					// Check if player two mouse is over minion
					if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_TAB))
					{
						if (playertwo::GetInstance()->getRect().x > BaseManager::GetInstance()->getRect2().x && playertwo::GetInstance()->getRect().x < BaseManager::GetInstance()->getRect2().w + BaseManager::GetInstance()->getRect2().x &&
							playertwo::GetInstance()->getRect().y > BaseManager::GetInstance()->getRect2().y && playertwo::GetInstance()->getRect().y < BaseManager::GetInstance()->getRect2().h + BaseManager::GetInstance()->getRect2().y) {
							if (GoldManager::GetInstance()->getGold(2) >= 20)
							{
								cout << "CREATE MINIONS2!!!!" << endl;
								newMinionX2 += 100;
								MinionManager::GetInstance()->addMinion(newMinionX2, newMinionY2, 2);
								if (newMinionX2 >= 700)
									newMinionX2 = 400;

								GoldManager::GetInstance()->subtractGold(20, 2);
							}
						}

						MinionManager::GetInstance()->SelectedKeyboard(playertwo::GetInstance()->getRect().x , playertwo::GetInstance()->getRect().y );
						SDL_Point mouse = { playertwo::GetInstance()->getRect().x, playertwo::GetInstance()->getRect().y };

						if (TowerManager::GetInstance()->KeyBoardClicked(mouse))
						{
							TowerManager::GetInstance()->TeamsTwoMinions -= 1;
							for each(Minion * minion in *MinionManager::GetInstance()->ReturnMinionsTeam2())
							{
								if (minion->InTower)
								{
									SDL_Rect temp = minion->getRect();
									temp.x += 250;
									minion->setRect(temp);
									minion->InTower = false;
									break;
								}
							}
						}
					}
				}
				//update 
				StormWarning::GetInstance()->Update(ftime);
				TowerManager::GetInstance()->Update(ftime);
				playertwo::GetInstance()->Update();

				for each(Minion * minion in *MinionManager::GetInstance()->ReturnMinionsTeam1())
				{
					if (TowerManager::GetInstance()->collidingWithTower(minion->getRect(), 1) && !minion->InTower)
					{
						minion->InTower = true;
						TowerManager::GetInstance()->TeamsOneMinions += 1;
					}
				}
				for each(Minion * minion in *MinionManager::GetInstance()->ReturnMinionsTeam2())
				{
					if (TowerManager::GetInstance()->collidingWithTower(minion->getRect(), 2) && !minion->InTower)
					{
						minion->InTower = true;
						TowerManager::GetInstance()->TeamsTwoMinions += 1;
					}
				}

				//draw
				Renderer::GetInstance()->ClearRenderer();

				
				BaseManager::GetInstance()->Draw();
				TowerManager::GetInstance()->Draw();

				
				MinionManager::GetInstance()->Draw();
				playertwo::GetInstance()->Draw();
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