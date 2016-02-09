#ifndef _TOWER_H_
#define _TOWER_H_

#include <iostream>
#include <SDL.h>


class Tower{
public:
	Tower(int x, int y);
	void Draw();
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* gRenderer);
private:
	SDL_Texture* text;
	SDL_Rect src, dest;
	SDL_Point offset;

};

#endif