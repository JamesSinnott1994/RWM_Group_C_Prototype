#pragma once

#include <iostream>
#include <SDL.h>

class Minion
{
public:
	Minion(int,int,int);
	~Minion();
	void Draw();
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
	void Update(int,int, float);
	void Selected(int, int);
	bool getSelected() { return m_selected; }
	void Attack();
	void WeatherEffect();

	SDL_Rect getRect();
	void setRect(SDL_Rect);
	
	void Disaster(int);
	bool colliding(SDL_Rect pos, int rad);
	void doDamage(int dmg);
	bool isAlive(){ return m_alive; }

	bool InTower;

private:
	//variables
	SDL_Texture* text;
	SDL_Texture* healthBar;
	SDL_Rect src, dest;
	SDL_Point offset;
	int team;
	float m_moveSpeed;
	float m_attackSpeed;
	float m_attackPower;
	int m_x, m_y;
	bool m_alive;
	int m_width, m_height;
	__int8 m_health;
	bool m_selected;
	bool m_selectCheck;
	bool recentlyMoved;
	float time;
	//methods
	void Move(int, int);

};

