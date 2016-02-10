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

};
#endif