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


	int health;
	SDL_Texture* text;
	SDL_Rect src, dest;
	SDL_Point offset;
	int m_team;
	
	// Background image
	SDL_Rect src2;
	SDL_Rect dest2;
	SDL_Texture* text2;

public:
	Base(SDL_Point, int);
	~Base()
	{
		
	}

	int getHealth();
	void setHealth(int pHealth);
	void Init(int width, int height);
	void Update();
	void Draw();
	void DrawBackground();
	void doDamage(int damage);
	SDL_Rect getRect();
	void createMinion();
	bool colliding(SDL_Rect pos, int rad);
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
};

#endif