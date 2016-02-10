#pragma once


#include <iostream> 
#include <SDL.h>			//SDL
#include <stdio.h>
#include <list>
#include "Minion.h"
#include "Renderer.h"
#include <vector>;


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
	void Selected(int mouseX, int mouseY);
	static const int REDTEAM = 0, BLUETEAM = 1;

	std::list<Minion*>* ReturnMinions();

private:
	MinionManager()
	{
		minions = std::list<Minion*>();
		
	}
	std::list<Minion*> minions;
	static bool instanceFlag;
	static MinionManager* instance;

};

