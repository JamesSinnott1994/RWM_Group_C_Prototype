#include "GoldManager.h"

bool GoldManager::instanceFlag = false;
GoldManager* GoldManager::instance = NULL;

GoldManager* GoldManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new GoldManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}


bool GoldManager::initializeTTF()
{
	//Loading success flag
	bool success = true;

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	loadTTFMedia();
	return success;
}

bool GoldManager::loadTTFMedia()
{
	//Loading success flag
	bool success = true;

	gFont = TTF_OpenFont("Font/ARDESTINE.ttf", 40);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		// Render text
		SDL_Color textColor = { 255, 127, 39 };
		if (!goldTeam1Text.loadFromRenderedText("Gold: " + to_string(GoldManager::GetInstance()->getGold(1)), textColor, gFont))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
		SDL_Color textColor2 = { 63, 72, 204 };
		if (!goldTeam2Text.loadFromRenderedText("Gold: " + to_string(GoldManager::GetInstance()->getGold(2)), textColor2, gFont))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
}

void GoldManager::addGold(int amount, int team)
{
	if (team == 1)
	{
		team1 += amount;
		cout << "Team 1 gold : " << team1 << endl;
	}
	else if (team == 2)
	{
		team2 += amount;
		cout << "Team 2 gold : " << team2 << endl;
	}
	loadTTFMedia();
}

void GoldManager::Draw()
{	
	
	goldTeam1Text.render(50, 5);
	goldTeam2Text.render(50, 580);
}