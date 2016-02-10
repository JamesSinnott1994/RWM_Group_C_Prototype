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

	for each  (Minion* minion in minions_Team1){

		minion->Update(mouseX, mouseY, t);
	}
	for each  (Minion* minion in minions_Team2){

		minion->Update(mouseX, mouseY, t);
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