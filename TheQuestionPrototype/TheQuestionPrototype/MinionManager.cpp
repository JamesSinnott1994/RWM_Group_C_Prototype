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
void MinionManager::Selected(int mouseX, int mouseY){
	for each  (Minion* minion in minions){

		minion->Selected(mouseX, mouseY);
	}
}

void MinionManager::addMinion(int x, int y, int team)
{
	Minion* temp = new Minion(x,y,team);

	minions.push_back(temp);
}
void MinionManager::Update(int mouseX, int mouseY, float t){

	for each  (Minion* minion in minions){

		minion->Update(mouseX, mouseY, t);
	}
}
void MinionManager::Draw(){

	for each  (Minion* minion in minions){

		minion->Draw();
	}
}

void MinionManager::DisasterOccured(int type)
{
	for each(Minion* minion in minions)
	{
		minion->Disaster(type);
	}
}