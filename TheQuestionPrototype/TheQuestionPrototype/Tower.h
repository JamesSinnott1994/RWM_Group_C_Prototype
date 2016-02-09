#ifndef _TOWER_H_
#define _TOWER_H_

#include <iostream>
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>


class Tower{
public:
	Tower(int x, int y);
	void Draw();
	void update(float time);
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
private:
	SDL_Texture* text;
	SDL_Texture* healthBar;
	SDL_Texture* statstext;
	SDL_Texture* storm;
	SDL_Texture* volcano;
	SDL_Texture* flood;
	SDL_Texture* eathq;
	SDL_Rect src, dest;
	SDL_Point offset;

	float timeSinceAttack;
	int health;
	bool displayStats;

	bool stormProof, volcanoProof, floodProof, earthquakeProof;
	void Disaster(int identifier);
	
};

#endif