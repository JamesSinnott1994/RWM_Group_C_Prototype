
#include "TowerManager.h"


using namespace std;

bool TowerManager::instanceFlag = false;
TowerManager* TowerManager::instance = NULL;

TowerManager* TowerManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new TowerManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

TowerManager::TowerManager(){

}

void TowerManager::addTower(int team, float x, float y)
{
	if (team == 1)
	Team_1_towers.push_back(new Tower(x, y));
	if (team == 2)
		Team_2_towers.push_back(new Tower(x, y));
}

void TowerManager::Draw()
{
	/*Call Draw on objects here*/
	for each(Tower * t in Team_1_towers)
	{
		t->Draw();
	}
	for each(Tower * t in Team_2_towers)
	{
		t->Draw();
	}
}
void TowerManager::Update(float time)
{

	for each(Tower * t in Team_1_towers)
	{
		t->update(time);
	}
	for each(Tower * t in Team_2_towers)
	{
		t->update(time);
	}
}
void TowerManager::mouseClicked(SDL_Point mouse)
{
	for each(Tower * t in Team_1_towers)
	{
		t->mouseClicked(mouse);
	}
	for each(Tower * t in Team_2_towers)
	{
		t->mouseClicked(mouse);
	}
}
void TowerManager::DisasterOccured(int type)
{
	for each(Tower * t in Team_1_towers)
	{
		t->Disaster(type);
	}
	for each(Tower * t in Team_2_towers)
	{
		t->Disaster(type);
	}
}