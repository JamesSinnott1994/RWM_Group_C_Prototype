#ifndef _TOWER_H_
#define _TOWER_H_

#include <iostream>
#include "Renderer.h"
#include <SDL.h>
#include <SDL_image.h>
#include <list>


class Tower{
public:
	bool Tower::colliding(SDL_Rect pos, int rad);
	Tower(int x, int y, int team);
	void Draw(int noOfMinions, int team);
	void update(float time);
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
	bool mouseClicked(SDL_Point mouse, int noOfMinions);
	void Disaster(int identifier);
	bool getAlive(){ return alive; }
	void setDamage(int dmg);
	bool collidingWithTower(SDL_Rect pos);

private:
	SDL_Texture* text;
	SDL_Texture* healthBar;
	SDL_Texture* statstext;
	SDL_Texture* storm;
	SDL_Texture* volcano;
	SDL_Texture* flood;
	SDL_Texture* eathq;
	SDL_Texture* radius;
	SDL_Rect src, dest;
	SDL_Point offset;
	Uint32 last_mouse_clicked_time;
	bool alive;
	int m_team;

	int NoOfTeam1Minions;
	int NoOfTeam2Minions;

	std::list<SDL_Rect> minionTeam1Rects;
	std::list<SDL_Rect> minionTeam2Rects;
	

	float timeSinceAttack;
	int health;
	bool displayStats;

	bool stormProof, volcanoProof, floodProof, earthquakeProof;
	
	SDL_Rect rect;
};

#endif