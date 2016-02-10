#ifndef _TOWER_H_
#define _TOWER_H_

#include <iostream>
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>


class Tower{
public:
	Tower(int x, int y, int team);
	void Draw();
	void update(float time);
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
	void mouseClicked(SDL_Point mouse);
	void Disaster(int identifier);
	bool getAlive(){ return alive; }
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
	Uint32 last_mouse_clicked_time;
	bool alive;
	int m_team;
	

	float timeSinceAttack;
	int health;
	bool displayStats;

	bool stormProof, volcanoProof, floodProof, earthquakeProof;
	
	
};

#endif