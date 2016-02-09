#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <SDL.h>
#include "Renderer.h"
#include <SDL_image.h>

class Base
{
private:
	static bool instanceFlag;
	static Base* instance;

	__int8 health;
	SDL_Texture* text;
	SDL_Rect src, dest;
	SDL_Point offset;

	Base::Base()
	{
		health = 10;
	}

public:
	static Base* GetInstance();
	~Base()
	{
		instanceFlag = false;
	}

	__int8 getHealth();
	void setHealth(int pHealth);
	void Init(int width, int height);
	void Update();
	void Draw();
	SDL_Rect getRect();
	void createMinion();

	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
};

#endif