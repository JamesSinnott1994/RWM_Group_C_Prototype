#include "MinionManager.h"

bool MinionManager::instanceFlag = false;
MinionManager* MinionManager::instance = NULL;

MinionManager* MinionManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new MinionManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void MinionManager::Init( SDL_Renderer* gRenderer)
{

}
void MinionManager::SelectedMouse(int mouseX, int mouseY){
	for each  (Minion* minion in minions_Team1){

		minion->Selected(mouseX, mouseY);
	}
}
void MinionManager::SelectedKeyboard(int mouseX, int mouseY)
{
	for each  (Minion* minion in minions_Team2){

		minion->Selected(mouseX, mouseY);
	}
}

void MinionManager::addMinion(int x, int y, int team)
{
	Minion* temp = new Minion(x,y,team);
	if (team == 1)
	{
		minions_Team1.push_back(temp);
	}
	if (team == 2)
	{
		minions_Team2.push_back(temp);
	}
	
}
void MinionManager::Update(int mouseX, int mouseY, float t){
	for (std::list<Minion*>::iterator it = minions_Team1.begin(); it != minions_Team1.end();)
	{
		(*it)->Update(mouseX, mouseY, t);
		if ((*it)->isAlive())
		{
			it++;
		}
		else
		{
			it = minions_Team1.erase(it);
		}
	}
	for (std::list<Minion*>::iterator it = minions_Team2.begin(); it != minions_Team2.end();)
	{
		(*it)->Update(mouseX, mouseY, t);
		if ((*it)->isAlive())
		{
			it++;
		}
		else
		{
			it = minions_Team2.erase(it);
		}
	}
}
void MinionManager::Draw(){

	for each  (Minion* minion in minions_Team1){

		minion->Draw();
	}
	for each  (Minion* minion in minions_Team2){

		minion->Draw();
	}
}


void MinionManager::DisasterOccured(int type)
{
	for each(Minion* minion in minions_Team1)
	{
		minion->Disaster(type);
	}
	for each(Minion* minion in minions_Team2)
	{
		minion->Disaster(type);
	}

}

std::list<Minion*>* MinionManager::ReturnMinionsTeam1()
{
	return &minions_Team1;
}

std::list<Minion*>* MinionManager::ReturnMinionsTeam2()
{
	return &minions_Team2;

}
void MinionManager::attackMinion(int team, int damage, SDL_Rect towerpos)
{
	if (team == 1)
	{
		for each  (Minion* minion in minions_Team2){

			if (minion->colliding(towerpos,150))
			{
				minion->doDamage(damage);
				break;
			}
		}
	}
	else if (team == 2)
	{
		for each  (Minion* minion in minions_Team1){

			if (minion->colliding(towerpos,150))
			{
				minion->doDamage(damage);
				break;
			}
		}
	}
}