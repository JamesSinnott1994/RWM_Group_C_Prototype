#pragma once


#include <iostream> 
#include <SDL.h>			//SDL
#include <stdio.h>
#include <list>
#include "Minion.h"
#include "Renderer.h"
#include <vector>


class MinionManager
{
public:
	//MinionManager();
	~MinionManager(){
		instanceFlag = false;
	}
	void Init(SDL_Renderer* gRenderer);
	void Draw();
	static MinionManager* GetInstance();
	void addMinion(int, int, int);
	void addImage(SDL_Rect pRect, int src);
	void Update(int mouseX, int mouseY, float t);
	void SelectedMouse(int mouseX, int mouseY);
	void SelectedKeyboard(int mouseX, int mouseY);
	static const int REDTEAM = 0, BLUETEAM = 1;
	void DisasterOccured(int type);

	std::list<Minion*>* ReturnMinionsTeam1();
	std::list<Minion*>* ReturnMinionsTeam2();

	void attackMinion(int team, int damage, SDL_Rect towerpos);
	std::list<Minion*>* ReturnMinions();

private:
	MinionManager()
	{
		minions_Team1 = std::list<Minion*>();
		minions_Team2 = std::list<Minion*>();
	}
	std::list<Minion*> minions_Team1;
	std::list<Minion*> minions_Team2;
	static bool instanceFlag;
	static MinionManager* instance;
	
};

