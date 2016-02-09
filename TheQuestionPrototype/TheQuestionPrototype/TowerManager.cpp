
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
}