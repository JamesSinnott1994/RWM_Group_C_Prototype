#include "BaseManager.h"

bool BaseManager::instanceFlag = false;
BaseManager* BaseManager::instance = NULL;

BaseManager* BaseManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new BaseManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}


void BaseManager::Init()
{
	team1 = new Base(SDL_Point{ 484, 0 }, 1);
	team2 = new Base(SDL_Point{ 484, 553 }, 2);
}
void BaseManager::Draw()
{
	team1->Draw();
	team2->Draw();
}
void BaseManager::Update(float time)
{

}

SDL_Rect BaseManager::getRect1()
{
	return team1->getRect();
}
SDL_Rect BaseManager::getRect2()
{
	return team2->getRect();
}