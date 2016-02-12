#ifndef _BASEMANAGER_H_
#define _BASEMANAGER_H_

#include "Base.h"
#include <iostream>
using namespace std;

class BaseManager {
private:

	Base* team1;
	Base* team2;
	Base* background;

	static bool instanceFlag;
	static BaseManager* instance;
	BaseManager(){}
public:
	static BaseManager* GetInstance();
	void attackBase(int team, int damage, SDL_Rect minionPos);
	~BaseManager()
	{
		delete instance;
		instanceFlag = false;
	}
	SDL_Rect getRect1();
	SDL_Rect getRect2();
	void Draw();
	void DrawBackground();
	void Update(float time);
	void Init();
};
#endif