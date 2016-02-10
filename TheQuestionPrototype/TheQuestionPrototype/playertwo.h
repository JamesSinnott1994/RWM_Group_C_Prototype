#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <SDL.h>
#include "Renderer.h"
#include "KeyBoardInput.h"

class playertwo
{
private:
	static bool instanceFlag;
	static playertwo* instance;

	float x;
	float y;
	float w;
	float h;

	playertwo::playertwo()
	{

	}

public:
	static playertwo* GetInstance();
	~playertwo()
	{
		instanceFlag = false;
	}
	void Init();
	void Update();
	void Draw();

	SDL_Rect getRect();
};