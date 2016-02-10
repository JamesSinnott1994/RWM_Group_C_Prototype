#ifndef _TOWERMANAGER_H_
#define _TOWERMANAGER_H_

#include "Tower.h"
#include <list>
#include <iostream>
using namespace std;


class TowerManager
{
private:
	static bool instanceFlag;
	static TowerManager* instance;
	TowerManager();
	
	list<Tower*> Team_1_towers;
	list<Tower*> Team_2_towers;




public:

	static TowerManager* GetInstance();
	~TowerManager()
	{
		delete instance;
		instanceFlag = false;
	}
	void addTower(int team, float x, float y);
	void Draw();
	void Update(float time);
	bool mouseClicked(SDL_Point mouse);
	bool KeyBoardClicked(SDL_Point mouse);
	void DisasterOccured(int type);
	bool collidingWithTower(SDL_Rect pos, int team);

	int TeamsOneMinions;
	int TeamsTwoMinions;
	
};
#endif