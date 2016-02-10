#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
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
	SDL_Texture* mouse;

	playertwo::playertwo()
	{

	}
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
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