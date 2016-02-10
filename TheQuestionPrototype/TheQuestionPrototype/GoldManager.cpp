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

}