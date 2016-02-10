#ifndef _GOLDMANAGER_H_
#define _GOLDMANAGER_H_

#include "Base.h"
#include <iostream>
using namespace std;

class GoldManager
{
private:

	int team1;
	int team2;
	static bool instanceFlag;
	static GoldManager* instance;
	GoldManager(){
		team1 = 300;
		team2 = 300;
	}

public:

	static GoldManager* GetInstance();
	~GoldManager()
	{
		delete instance;
		instanceFlag = false;
	}
	void addGold(int amount, int team);
	int getGold(int team)
	{
		if (team == 1){ return team1; }
		else if (team == 2){ return team2; }
	}
	void subtractGold(int amount, int team)
	{
		if (team == 1)
		{
			team1 -= amount;
			cout << "Team 1 gold : " << team1 << endl;
		}
		else if (team == 2)
		{
			team2 -= amount;
			cout << "Team 2 gold : " << team2 << endl;
		}
	}

};
#endif